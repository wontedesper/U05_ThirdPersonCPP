#include "BTService_Wizard.h"
#include "Global.h"
#include "Characters/CPlayer.h"
#include "Characters/CEnemy_AI.h"
#include "Characters/CAIController.h"
#include "Components/CBehaviorComponent.h"
#include "Components/CStateComponent.h"

UBTService_Wizard::UBTService_Wizard()
{
	NodeName = "Wizard";
}

void UBTService_Wizard::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	ACAIController* controller = Cast<ACAIController>(OwnerComp.GetOwner());
	UCBehaviorComponent* behavior = CHelpers::GetComponent<UCBehaviorComponent>(controller);

	ACEnemy_AI* aiPawn = Cast<ACEnemy_AI>(controller->GetPawn());
	UCStateComponent* state = CHelpers::GetComponent<UCStateComponent>(aiPawn);

	CheckTrue(state->IsDeadMode());

	if (state->IsHittedMode())
	{
		behavior->SetHittedMode();
		return;
	}

	ACPlayer* target = behavior->GetTargetPlayer();
	if (target == nullptr)
	{
		behavior->SetWaitMode();
		controller->ClearFocus(EAIFocusPriority::Gameplay);

		return;
	}
	else
	{
		UCStateComponent* targetState = CHelpers::GetComponent<UCStateComponent>(target);
		if (targetState->IsDeadMode())
		{
			behavior->SetWaitMode();
			return;
		}
	}

	controller->SetFocus(target);

	float distane = aiPawn->GetDistanceTo(target);
	if (distane < controller->GetBehaviorRange())
	{
		behavior->SetAvoidMode();
		return;
	}

	if (distane < controller->GetSightRadius())
	{
		behavior->SetActionMode();
		return;
	}
}
