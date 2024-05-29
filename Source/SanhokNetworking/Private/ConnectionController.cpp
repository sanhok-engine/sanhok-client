#include "ConnectionController.h"
#include "protocol/protocol.hpp"

UConnectionController::UConnectionController()
{
	PrimaryComponentTick.bCanEverTick = false;

	ConnectionTCP = CreateDefaultSubobject<UConnectionTCP>(TEXT("Connection TCP"));
	// connection_tcp_->AttachTo(RootComponent);
	ConnectionTCP->set_on_receive([this](TArray<uint8>&& buffer, bool size_prefixed)
	{
		Deserialize(MoveTemp(buffer), size_prefixed);
	});
}

void UConnectionController::BeginPlay()
{
	if (!ConnectionTCP)
	{
		UE_LOG(LogNet, Error, TEXT("ConnectionTCP not set"));
		return;
	}
	ConnectionTCP->Connect("127.0.0.1:50000");
}

void UConnectionController::Deserialize(TArray<uint8>&& buffer, const bool size_prefixed)
{
	using namespace sanhok::game::protocol;
	
	AsyncTask(ENamedThreads::GameThread, [this, size_prefixed, buffer = MoveTemp(buffer)]() mutable
	{
		const auto protocol = size_prefixed ? GetSizePrefixedProtocol(buffer.GetData()) : GetProtocol(buffer.GetData());
		if (!protocol) return;

		switch (protocol->protocol_type())
		{
		case ProtocolType::ClientJoin:
		{
			const auto client_join = protocol->protocol_as<ClientJoin>();

			client_id_ = client_join->client_id();
			UE_LOG(LogNet, Display, TEXT("ClientJoin: %d, %d"), client_join->client_id(), client_join->udp_port());

			//TODO: Test open/close udp connection
			break;
		}

		default:
			break;
		}
	});
}
