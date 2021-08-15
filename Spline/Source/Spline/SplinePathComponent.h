#pragma once

#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "BezierDataTable.h"
#include "SplinePathComponent.generated.h"

UCLASS()
class SPLINE_API USplinePathComponent : public USplineComponent
{
	GENERATED_BODY()

public:
	USplinePathComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UDataTable* PathDataTable;

private:
	void CreateSplinePoints();
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;


};
