#include "CMontagesComponent.h"
#include "Global.h"
#include "GameFramework/Character.h"

UCMontagesComponent::UCMontagesComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

}


void UCMontagesComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<FMontageData*> datas;
	DataTable->GetAllRows<FMontageData>("", datas);

	for (int32 i = 0; i < (int32)EStateType::Max; i++)
	{
		for (FMontageData* data : datas)
		{
			if ((EStateType)i == data->Type)
			{
				Datas[i] = data;
				continue;
			}
		}
	}


}

void UCMontagesComponent::PlayAnimMontage(EStateType InType)
{
	ACharacter* character = Cast<ACharacter>(GetOwner());
	CheckNull(character);

	const FMontageData* data = Datas[(int32)InType];

	if (!!data)
	{
		if (!!data->AnimMontage)
			character->PlayAnimMontage(data->AnimMontage, data->PlayRate, data->StartSection);

	}

}
