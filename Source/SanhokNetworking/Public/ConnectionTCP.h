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
	void Disconnect();
	void Start();
	void Stop();
	
	void Send(TSharedPtr<flatbuffers::DetachedBuffer> buffer);
	
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	bool GetRemoteAddress(FInternetAddr& target_address) const;
	void set_on_receive(TFunction<void(TArray<uint8>&&, bool)>&& on_receive) { on_receive_ = on_receive; }

private:
	void Receive();
	TFunction<void(TArray<uint8>&&, bool)> on_receive_;

	FSocket* socket_{nullptr};
	TAtomic<bool> is_connected_{false};
	TAtomic<bool> is_running_{false};
	TQueue<TSharedPtr<flatbuffers::DetachedBuffer>, EQueueMode::Mpsc> send_queue_;

	FRunnableThread* receive_thread_;
	FRunnableThread* send_thread_;
};
