#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CBehaviorComponent.generated.h"

UENUM(BlueprintType)
enum class EBehaviorType : uint8
{
	Wait, Approach, Action, Patrol, Hitted, Avoid,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBehaviorTypeChaged, EBehaviorType, InPrevType, EBehaviorType, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_API UCBehaviorComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure) bool IsWaitMode();
	UFUNCTION(BlueprintPure) bool IsApproachMode();
	UFUNCTION(BlueprintPure) bool IsActionMode();
	UFUNCTION(BlueprintPure) bool IsPatrolMode();
	UFUNCTION(BlueprintPure) bool IsHittedMode();
	UFUNCTION(BlueprintPure) bool IsAvoidMode();

public:
	void SetWaitMode();
	void SetApproachMode();
	void SetActionMode();
	void SetPatrolMode();
	void SetHittedMode();
	void SetAvoidMode();

	FORCEINLINE void SetBlackBoard(class UBlackboardComponent* InBlackboard) { Blackboard = InBlackboard; }

	class ACPlayer* GetTargetPlayer();
	FVector GetWarpLocation();

private:
	void ChangeType(EBehaviorType InType);
	EBehaviorType GetType();


public:
	UPROPERTY(BlueprintAssignable)
		FBehaviorTypeChaged OnBehaviorTypeChaged;

private:
	UPROPERTY(EditAnywhere)
		FName BehaviorKey = "Behavior";

	UPROPERTY(EditAnywhere)
		FName PlayerKey = "Player";

	UPROPERTY(EditAnywhere)
		FName WarpLocationKey = "WarpLocation";

private:
	class UBlackboardComponent* Blackboard;
		
};
