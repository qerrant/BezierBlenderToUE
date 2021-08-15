#include "SplinePathComponent.h"
#define HANDLE_SCALE 3.0f

USplinePathComponent::USplinePathComponent()
{
	bAllowDiscontinuousSpline = true;
}

#if WITH_EDITOR
void USplinePathComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(USplinePathComponent, PathDataTable))
	{
		UE_LOG(LogTemp, Warning, TEXT("Table was changed"));
		CreateSplinePoints();
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif

void USplinePathComponent::CreateSplinePoints()
{
	ClearSplinePoints(true);

	if (ensure(PathDataTable != nullptr))
	{
		UE_LOG(LogTemp, Warning, TEXT("Table was found"));
		const FString ContextString = "Bezier Data Table";
		TArray<FBezierDataTable*> Rows;

		PathDataTable->GetAllRows<FBezierDataTable>(ContextString, Rows);

		for (int i = 0; i < Rows.Num(); i++)
		{
			const FVector BezierPointCoord = FVector((*Rows[i]).px, (*Rows[i]).py, (*Rows[i]).pz);
			const FVector PointLocation = BezierPointCoord;

			AddSplineWorldPoint(PointLocation);

			const FVector BezierLeftHandleCoord = FVector((*Rows[i]).hlx, (*Rows[i]).hly, (*Rows[i]).hlz);
			const FVector BezierRightHandleCoord = FVector((*Rows[i]).hrx, (*Rows[i]).hry, (*Rows[i]).hrz);
			const FVector LeftTangent = (PointLocation - BezierLeftHandleCoord) * HANDLE_SCALE;
			const FVector RightTangent = (BezierRightHandleCoord - PointLocation) * HANDLE_SCALE;

			SetTangentsAtSplinePoint(i, LeftTangent, RightTangent, ESplineCoordinateSpace::World, true);
		}
	}
}
