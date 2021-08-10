// Fill out your copyright notice in the Description page of Project Settings.


#include "SplineActor.h"

// Unreal scale of handles
#define HANDLE_SCALE 3.0f

// Sets default values
ASplineActor::ASplineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Spline Component
	Spline = CreateDefaultSubobject<USplineComponent>(FName("Spline"));
	// Set as root component 
	RootComponent = Spline;
	// Allow Discontinuous Spline
	Spline->bAllowDiscontinuousSpline = true;

}

// Create spline points
void ASplineActor::CreateSplinePoints()
{
	// Remove old points
	Spline->ClearSplinePoints(true);

	// Chack the specified DataTable
	if (ensure(BezierDataTable != nullptr))
	{
		const FString ContextString = "Bezier Data Table";
		TArray<FBezierDataTable*> Rows;

		// Get all rows from DataTable
		BezierDataTable->GetAllRows<FBezierDataTable>(ContextString, Rows);

		for (int i = 0; i < Rows.Num(); i++) 
		{
			const FVector BezierPointCoord = FVector((*Rows[i]).px, (*Rows[i]).py, (*Rows[i]).pz);
			const FVector PointLocation = BezierPointCoord + GetActorLocation();

			// Add point
			Spline->AddSplineWorldPoint(PointLocation);

			const FVector BezierLeftHandleCoord = FVector((*Rows[i]).hlx, (*Rows[i]).hly, (*Rows[i]).hlz);
			const FVector BezierRightHandleCoord = FVector((*Rows[i]).hrx, (*Rows[i]).hry, (*Rows[i]).hrz);
			const FVector LeftTangent = (PointLocation - (BezierLeftHandleCoord + GetActorLocation())) * HANDLE_SCALE;
			const FVector RightTangent = (BezierRightHandleCoord + GetActorLocation() - PointLocation) * HANDLE_SCALE;
			
			// Add handles
			Spline->SetTangentsAtSplinePoint(i, LeftTangent, RightTangent, ESplineCoordinateSpace::World);
		}
	}
}

// Called when the game starts or when spawned
void ASplineActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASplineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

