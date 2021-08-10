#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BezierDataTable.generated.h"

USTRUCT(BlueprintType)
struct FBezierDataTable : public FTableRowBase 
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float px;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float py;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float pz;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float hlx;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float hly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float hlz;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float hrx;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float hry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RoadPath)
        float hrz;
};
