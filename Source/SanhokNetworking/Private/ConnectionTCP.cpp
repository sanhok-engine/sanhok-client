#include "ConnectionTCP.h"
#include "SocketSubsystem.h"

UConnectionTCP::UConnectionTCP()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UConnectionTCP::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Stop();
	
	Super::EndPlay(EndPlayReason);
}

void UConnectionTCP::Connect(const FString& remote_endpoint)
{
	if (is_connected_) return;

	UE_LOG(LogNet, Display, TEXT("Connecting to %s ..."), *remote_endpoint);

	FIPv4Endpoint endpoint;
	if (!FIPv4Endpoint::Parse(remote_endpoint, endpoint))
	{
		UE_LOG(LogNet, Error, TEXT("Invalid remote endpoint %s"), *remote_endpoint);
		socket_->Close();
		return;
	}

	AsyncTask(ENamedThreads::Type::AnyBackgroundThreadNormalTask, [this, endpoint]
	{
		socket_ = FTcpSocketBuilder(TEXT("TCP Socket")).AsBlocking(); // for async
		if (!socket_->Connect(*endpoint.ToInternetAddr()))
		{
			UE_LOG(LogNet, Error, TEXT("Error connecting"));
			return;
		}

		socket_->SetNoDelay(true);
		is_connected_ = true;

		UE_LOG(LogNet, Display, TEXT("Connected to %s"), *endpoint.ToString());

		Start();
	});
}

void UConnectionTCP::Disconnect()
{
	if (!is_connected_.Exchange(false)) return;
	if (!socket_) return;

	if (!socket_->Shutdown(ESocketShutdownMode::ReadWrite))
	{
		UE_LOG(LogNet, Error, TEXT("Error shutting down socket"));
	}
	if (!socket_->Close())
	{
		UE_LOG(LogNet, Error, TEXT("Error closing socket"));
	}
}

void UConnectionTCP::Start()
{
	if (is_running_.Exchange(true)) return;

	AsyncTask(ENamedThreads::Type::AnyBackgroundHiPriTask, [this]
	{
		UE_LOG(LogNet, Display, TEXT("[%s] Receive thread running..."), *GetNameSafe(this));
		while (is_running_)
		{
			Receive();
		}
		UE_LOG(LogNet, Display, TEXT("[%s] Receive thread exiting"), *GetNameSafe(this));
	});

	AsyncTask(ENamedThreads::Type::AnyBackgroundHiPriTask, [this]
	{
		UE_LOG(LogNet, Display, TEXT("[%s] Send thread running..."), *GetNameSafe(this));
		while (is_running_)
		{
			TSharedPtr<flatbuffers::DetachedBuffer> buffer;
			if (!send_queue_.Dequeue(buffer)) continue;

			if (int32 bytes_sent; !socket_->Send(buffer->data(), buffer->size(), bytes_sent))
			{
				UE_LOG(LogNet, Error, TEXT("[%s] Error sending"), *GetNameSafe(this));
				Stop();
			}
		}
		UE_LOG(LogNet, Display, TEXT("[%s] Send thread exiting"), *GetNameSafe(this));
	});
}

void UConnectionTCP::Stop()
{
	if (!is_running_.Exchange(false)) return;

	Disconnect();
}

void UConnectionTCP::Send(TSharedPtr<flatbuffers::DetachedBuffer> buffer)
{
	if (!send_queue_.Enqueue(buffer))
	{
		UE_LOG(LogNet, Error, TEXT("[%s] Error enqueuing sending buffer"), *GetNameSafe(this));
	}
}

bool UConnectionTCP::GetRemoteAddress(FInternetAddr& target_address) const
{
	if (!socket_) return false;
	return socket_->GetPeerAddress(target_address);
}

void UConnectionTCP::Receive()
{
	if (!is_connected_) return;

	TArray<uint8> header_buffer;
	header_buffer.SetNum(sizeof(flatbuffers::uoffset_t));

	if (int32 bytes_read; !socket_->Recv(
		header_buffer.GetData(), header_buffer.Num(), bytes_read, ESocketReceiveFlags::Type::WaitAll))
	{
		UE_LOG(LogNet, Error, TEXT("Error receiving header"));
		Stop();
		return;
	}

	TArray<uint8> body_buffer;
	body_buffer.SetNum(flatbuffers::GetPrefixedSize(header_buffer.GetData()));

	if (int32 bytes_read; !socket_->Recv(
		body_buffer.GetData(), body_buffer.Num(), bytes_read, ESocketReceiveFlags::Type::WaitAll))
	{
		UE_LOG(LogNet, Error, TEXT("Error receiving body"));
		Stop();
		return;
	}

	on_receive_(MoveTemp(body_buffer), false);
}
