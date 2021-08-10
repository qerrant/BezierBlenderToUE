#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "BezierDataTable.generated.h"

USTRUCT(BlueprintType)
struct FBezierDataTable : public FTableRowBase 
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float px;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float py;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float pz;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float hlx;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float hly;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float hlz;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float hrx;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float hry;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float hrz;
};
