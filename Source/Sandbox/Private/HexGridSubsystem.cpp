#include "HexGridSubsystem.h"
#include "HexGridSettings.h"
#include "Engine/Engine.h"

void UHexGridSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	NoiseWrapperLvl1 = NewObject<UFastNoiseWrapper>(this);
	NoiseWrapperLvl1->SetupFastNoise();
}
