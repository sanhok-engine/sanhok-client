#pragma once

#include "flatbuffers/flatbuffers.h"
#include "ConnectionController.h"

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

	UFUNCTION(BlueprintCallable)
	void SetConnectionControllerComponent(UConnectionController* connection_controller)
	{
		connection_controller_ = connection_controller;
	}

private:
	void Receive();

	UPROPERTY()
	UConnectionController* connection_controller_{nullptr};

	FSocket* socket_{nullptr};
	TAtomic<bool> is_connected_{false};
	TAtomic<bool> is_running_{false};
};
