#include "CAnimNotifyState_Equip.h"
#include "Global.h"
#include "Components/CActionComponent.h"
#include "Actions/CActionData.h"
#include "Actions/CEquipment.h"

FString UCAnimNotifyState_Equip::GetNotifyName_Implementation() const
{
	return "Equip";
}

void UCAnimNotifyState_Equip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	CheckNull(MeshComp);

	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(action);

	action->GetCurrent()->GetEquipment()->Begin_Equip();
}

void UCAnimNotifyState_Equip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	CheckNull(MeshComp);

	UCActionComponent* action = CHelpers::GetComponent<UCActionComponent>(MeshComp->GetOwner());
	CheckNull(action);

	action->GetCurrent()->GetEquipment()->End_Equip();
}
