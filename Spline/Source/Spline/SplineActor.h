// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BezierDataTable.h"
#include "Components/SplineComponent.h"
#include "SplineActor.generated.h"

UCLASS()
class SPLINE_API ASplineActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplineActor();

	// Set Bezier DataTable
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* BezierDataTable;

	// Create Spline Component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USplineComponent* Spline;

	// Called from blueprint constructor
	UFUNCTION(BlueprintCallable)
	void CreateSplinePoints();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;	

};
