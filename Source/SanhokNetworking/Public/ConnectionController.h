#pragma once

#include "flatbuffers/flatbuffers.h"
#include "protocol/protocol.hpp"
#include "ConnectionTCP.h"
#include "ConnectionUDP.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConnectionController.generated.h"

// DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnClientJoin, uint32, client_id, uint16, udp_port);

UCLASS(ClassGroup=(Networking), meta=(BlueprintSpawnableComponent))
class SANHOKNETWORKING_API UConnectionController : public UActorComponent
{
	GENERATED_BODY()

public:
	UConnectionController();

	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void SetConnectionTCP(UConnectionTCP* ConnectionTCP) { ConnectionTCP_ = ConnectionTCP; }

	UFUNCTION(BlueprintCallable)
	void SetConnectionUDP(UConnectionUDP* ConnectionUDP) { ConnectionUDP_ = ConnectionUDP; }
	
	void Deserialize(TArray<uint8>&& buffer, bool size_prefixed);

private:
	void handle_client_join(const sanhok::game::protocol::ClientJoin* client_join);
	
	UConnectionTCP* ConnectionTCP_{nullptr};
	UConnectionUDP* ConnectionUDP_{nullptr};

	uint32 client_id_{0};
};
