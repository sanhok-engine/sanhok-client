#pragma once

#include "flatbuffers/flatbuffers.h"

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

	void Deserialize(TArray<uint8>&& buffer, bool size_prefixed);

	UPROPERTY(BlueprintReadOnly)
	FOnClientJoin OnClientJoin;

private:
	uint32 client_id_ {0};
};
