#pragma once

#include "flatbuffers/flatbuffers.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Networking.h"

#include "ConnectionTCP.generated.h"

UCLASS(ClassGroup=(Networking), meta=(BlueprintSpawnableComponent))
class SANHOKNETWORKING_API UConnectionTCP : public UActorComponent
{
	GENERATED_BODY()

public:
	UConnectionTCP();

	UFUNCTION(BlueprintCallable)
	void Connect(const FString& remote_endpoint);

	UFUNCTION(BlueprintCallable)
	void Disconnect();

	UFUNCTION(BlueprintCallable)
	void Start();

	UFUNCTION(BlueprintCallable)
	void Stop();

	void set_on_receive(TFunction<void(TArray<uint8>&&, bool)>&& on_receive) { on_receive_ = on_receive; }

private:
	void Receive();
	TFunction<void(TArray<uint8>&&, bool)> on_receive_;

	FSocket* socket_{nullptr};
	TAtomic<bool> is_connected_{false};
	TAtomic<bool> is_running_{false};
};
