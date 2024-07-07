#pragma once

#include "CoreMinimal.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Subsystems/WorldSubsystem.h"
#include "FastNoiseWrapper.h"
#include "HexGridSubsystem.generated.h"

UCLASS()
class SANDBOX_API UHexGridSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	void Initialize(FSubsystemCollectionBase& Collection) override;
	UFastNoiseWrapper* NoiseWrapperLvl1;
};
