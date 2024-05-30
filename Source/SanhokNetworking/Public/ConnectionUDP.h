#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Networking.h"

#include "ConnectionUDP.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SANHOKNETWORKING_API UConnectionUDP : public UActorComponent
{
	GENERATED_BODY()

public:
	UConnectionUDP();

	void Open(const FIPv4Endpoint& local_endpoint = {FIPv4Address {0, 0, 0, 0}, 0}, int32 receive_buffer_size = 65536);
	void Close();
	void Connect(const FInternetAddr& remote_address);

	bool GetLocalAddress(FInternetAddr& target_address);

private:
	FSocket* socket_{nullptr};
	TAtomic<bool> is_open_{false};
	int32 receive_buffer_size_ {0};
};
