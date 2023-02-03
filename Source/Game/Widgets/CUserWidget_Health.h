#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_Health.generated.h"

UCLASS()
class GAME_API UCUserWidget_Health : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent)
		void Update(float InHealth, float InMaxHealth);
};
