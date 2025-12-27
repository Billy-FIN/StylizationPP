#pragma once

#include "CoreMinimal.h"
#include "StylizationSettings.generated.h"

UENUM(BlueprintType)
enum class EStylizationMode : uint8
{
	None		UMETA(DisplayName = "None"),
	PixelArt	UMETA(DisplayName = "Pixel Art")
};

USTRUCT(BlueprintType)
struct STYLIZATIONPP_API FStylizationSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stylization")
	EStylizationMode Mode = EStylizationMode::None;

	// PixelArt Parameters
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pixel Art", meta = (ClampMin = "0.1", ClampMax = "10.0"))
	float Pixelation = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pixel Art", meta = (ClampMin = "2.0", ClampMax = "256.0"))
	float NumColors = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pixel Art", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float Spread = 0.05f;

	FStylizationSettings()
		: Mode(EStylizationMode::None)
		, Pixelation(1.0f)
		, NumColors(10.0f)
		, Spread(0.05f)
	{}
};

