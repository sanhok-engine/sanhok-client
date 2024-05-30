#include "ConnectionController.h"
#include "SocketSubsystem.h"

using namespace sanhok::game::protocol;

UConnectionController::UConnectionController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UConnectionController::Start()
{
	if (!ConnectionTCP_ || !ConnectionUDP_)
	{
		UE_LOG(LogNet, Error, TEXT("Connection components not set"));
		return;
	}
	
	ConnectionTCP_->set_on_receive([this](TArray<uint8>&& buffer, bool size_prefixed)
	{
		Deserialize(MoveTemp(buffer), size_prefixed);
	});

	ConnectionTCP_->Connect("127.0.0.1:50000");
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
			handle_client_join(protocol->protocol_as<ClientJoin>());
			break;

		default:
			break;
		}
	});
}

void UConnectionController::handle_client_join(const sanhok::game::protocol::ClientJoin* client_join)
{
	client_id_ = client_join->client_id();
	UE_LOG(LogNet, Display, TEXT("[ClientJoin] id(%d), udp_port(%d)"), client_join->client_id(), client_join->udp_port());

	TSharedRef<FInternetAddr> remote_address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	if (!ConnectionTCP_->GetRemoteAddress(*remote_address))
	{
		UE_LOG(LogNet, Display, TEXT("Invalid remote address"));
		return;
	}
	ConnectionUDP_->Open();
	ConnectionUDP_->Connect(*remote_address);

	// Send ClientJoin response
	
	TSharedRef<FInternetAddr> udp_address = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	if (!ConnectionUDP_->GetLocalAddress(*udp_address))
	{
		UE_LOG(LogNet, Display, TEXT("Invalid UDP local address"));
		return;
	}
	
	flatbuffers::FlatBufferBuilder builder {128};
	const auto client_join_response = CreateClientJoin(builder, client_id_, udp_address->GetPort());
	builder.FinishSizePrefixed(CreateProtocol(builder, ProtocolType::ClientJoin, client_join_response.Union()));

	ConnectionTCP_->Send(MakeShared<flatbuffers::DetachedBuffer>(builder.Release()));
}
