#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"

UENUM(BlueprintType)
enum class EWalkSpeedTpye : uint8
{
	Sneak, Walk, Run, Max
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCStatusComponent();

	void IncreaseHealth(float InAmount);
	void DecreaseHealth(float InAmount);

protected:
	virtual void BeginPlay() override;

public:
	FORCEINLINE float GetSneakSpeed() { return Speed[(int32)EWalkSpeedTpye::Sneak]; }
	FORCEINLINE float GetWalkSpeed() { return Speed[(int32)EWalkSpeedTpye::Walk]; }
	FORCEINLINE float GetRunSpeed() { return Speed[(int32)EWalkSpeedTpye::Run]; }
	FORCEINLINE bool IsCanMove() { return bCanMove; }

	FORCEINLINE float GetMaxHealth() { return MaxHealth; }
	FORCEINLINE float GetHealth() { return Health; }

	void SetMove();
	void SetStop();

	void SetSpeed(EWalkSpeedTpye InType);


private:
	UPROPERTY(EditAnywhere, Category = "Health")
		float MaxHealth = 100.f;

	UPROPERTY(EditAnywhere, Category = "Speed")
		float Speed[(int32)EWalkSpeedTpye::Max] = { 200, 400, 600 };
		
private:
	float Health;

	bool bCanMove = true;
};
