#pragma once

#include "flatbuffers/flatbuffers.h"
#include "ConnectionTCP.h"
#include "ConnectionUDP.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ConnectionController.generated.h"

DECLARE_DYNAMIC_DELEGATE_TwoParams(FOnClientJoin, uint32, client_id, uint16, udp_port);

UCLASS(ClassGroup=(Networking), meta=(BlueprintSpawnableComponent))
class SANHOKNETWORKING_API UConnectionController : public UActorComponent
{
	GENERATED_BODY()

public:
	UConnectionController();

	virtual void BeginPlay() override;

	void Deserialize(TArray<uint8>&& buffer, bool size_prefixed);

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	FOnClientJoin OnClientJoin;

private:
	UPROPERTY()
	UConnectionTCP* ConnectionTCP{nullptr};

	// UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess))
	// UConnectionUDP* connection_udp_{nullptr};

	uint32 client_id_{0};
};
