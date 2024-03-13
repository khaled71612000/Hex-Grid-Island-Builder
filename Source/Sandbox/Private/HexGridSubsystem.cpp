#include "HexGridSubsystem.h"
#include "HexGridSettings.h"
#include "Engine/Engine.h"

void UHexGridSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	//// Get the game user settings
	//UHexGridSettings* settings = GetMutableDefault<UHexGridSettings>();
	//UWorld* World = GetWorld();
	//if (World && World->GetGameInstance())
	//{
	//	if (settings)
	//	{
	//		// Print a message to the screen during initialization
	//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(settings->GridHeight));
	//	}
	//}
}