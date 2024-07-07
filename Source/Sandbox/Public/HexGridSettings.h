#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HexGridSettings.generated.h"

UCLASS(Config = HexGridSettings, defaultconfig, meta = (DisplayName = "Hex Grid Settings"))
class SANDBOX_API UHexGridSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "HexGrid|Layout")
	float TileHorizontalOffset = 86.602539f;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "HexGrid|Layout")
	float OddRowHorizontalOffset = 43.30127f;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "HexGrid|Layout")
	float TileVerticalOffset = 75.0f;
};
