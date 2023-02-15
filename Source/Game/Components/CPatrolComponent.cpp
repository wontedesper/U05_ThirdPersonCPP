#include "CPatrolComponent.h"
#include "Global.h"
#include "Characters/CPatrolPath.h"
#include "Components/SplineComponent.h"

UCPatrolComponent::UCPatrolComponent()
{

}


bool UCPatrolComponent::GetMoveTo(FVector& OutLocation, float& OutAcceptanceRadius)
{
	OutLocation = FVector::ZeroVector;
	OutAcceptanceRadius = AcceptanceRadius;
	CheckNullResult(Path, false);

	OutLocation = Path->GetSpline()->GetLocationAtSplinePoint(Index, ESplineCoordinateSpace::World);

	return true;
}

void UCPatrolComponent::UpdateNext()
{
	CheckNull(Path);

	int32 count = Path->GetSpline()->GetNumberOfSplinePoints();

	//Reverse
	if (bReverse)
	{
		if (Index > 0)
		{
			Index--;
			return;
		}

		if (Path->GetSpline()->IsClosedLoop())
		{
			Index = count - 1;
			return;
		}

		Index = 1;
		bReverse = false;

		return;
	}

	//Forward
	if (Index < count - 1)
	{
		Index++;
		return;
	}

	if (Path->GetSpline()->IsClosedLoop())
	{
		Index = 0;
		return;
	}

	Index = count - 2;
	bReverse = true;
}

void UCPatrolComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


