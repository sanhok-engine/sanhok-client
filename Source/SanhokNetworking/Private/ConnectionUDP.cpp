#include "SanhokNetworking.h"
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
		UE_LOG(LogNet, Error, TEXT("Error creating UDP socket"));
		is_open_ = false;
		return;
	}

	socket_->Bind(*local_endpoint.ToInternetAddr());
	// socket_->SetReceiveBufferSize(receive_buffer_size, new_size);
	receive_buffer_size_ = receive_buffer_size;
}

void UConnectionUDP::Close()
{
	if (!is_open_.Exchange(false)) return;

	socket_->Close();
	ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(socket_);
}
