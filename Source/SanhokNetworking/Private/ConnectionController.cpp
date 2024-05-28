#include "ConnectionController.h"
#include "protocol/protocol.hpp"

UConnectionController::UConnectionController()
{
	PrimaryComponentTick.bCanEverTick = false;
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

			// OnClientJoin.Execute(client_join->client_id(), client_join->udp_port());
			client_id_ = client_join->client_id();
			UE_LOG(LogTemp, Display, TEXT("ClientJoin: %d, %d"), client_join->client_id(), client_join->udp_port());
			break;
		}

		default:
			break;
		}
	});
}
