#include "ConnectionUDP.h"
#include "SocketSubsystem.h"

UConnectionUDP::UConnectionUDP()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UConnectionUDP::Open(const FIPv4Endpoint& local_endpoint, const int32 receive_buffer_size)
{
	if (is_open_.Exchange(true)) return;

	socket_ = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_DGram, TEXT("UDP Socket"), false);
	if (!socket_)
	{
		UE_LOG(LogNet, Error, TEXT("[%s] Error creating socket"), *GetNameSafe(this));
		is_open_ = false;
		return;
	}

	if (!socket_->Bind(*local_endpoint.ToInternetAddr()))
	{
		UE_LOG(LogNet, Error, TEXT("[%s] Error binding local address"), *GetNameSafe(this));
	}
	// socket_->SetReceiveBufferSize(receive_buffer_size, new_size);
	receive_buffer_size_ = receive_buffer_size;

	TSharedRef<FInternetAddr> local_address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	GetLocalAddress(*local_address);
	UE_LOG(LogNet, Display, TEXT("[%s] Bound on %s"), *GetNameSafe(this), *local_address->ToString(true));
}

void UConnectionUDP::Close()
{
	if (!is_open_.Exchange(false) || !socket_) return;

	socket_->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(socket_);
}

void UConnectionUDP::Connect(const FInternetAddr& remote_address)
{
	if (!socket_) return;

	if (!socket_->Connect(remote_address))
	{
		UE_LOG(LogNet, Error, TEXT("[%s] Error connecting"), *GetNameSafe(this));
	}
}

bool UConnectionUDP::GetLocalAddress(FInternetAddr& target_address)
{
	if (!socket_) return false;
	
	socket_->GetAddress(target_address);
	return true;
}
