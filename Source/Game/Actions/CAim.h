#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/TimelineComponent.h"
#include "CAim.generated.h"

UCLASS()
class GAME_API UCAim : public UObject
{
	GENERATED_BODY()

	
public:
	UCAim();

	void BeginPlay(class ACharacter* InOwnerCharacter);
	void Tick(float DeltaTime);

public:
	FORCEINLINE bool IsAvaliable() { return SpringArm != nullptr && Camera != nullptr; }
	FORCEINLINE bool IsZooming() { return bZooming; }

	void On();
	void Off();

private:
	UFUNCTION()
		void Zooming(float Output);

private:
	class ACharacter* OwnerCharacter;
	class USpringArmComponent* SpringArm;
	class UCameraComponent* Camera;

	bool bZooming;

private:
	class UCurveFloat* Curve;
	FTimeline Timeline;
	FOnTimelineFloat TimelineFloat;

	class ACHUD* Hud;
};
