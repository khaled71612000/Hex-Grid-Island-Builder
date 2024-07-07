#include "HexManager.h"
#include "HexTile.h"
#include "DrawDebugHelpers.h"
#include "HexGridSubsystem.h"

AHexManager::AHexManager()
{
	PrimaryActorTick.bCanEverTick = false;
	bRunConstructionScriptOnDrag = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	WaterMeshComp = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WaterMeshComp"));
	WaterMeshComp->SetupAttachment(RootComponent);
	WaterMeshComp->CastShadow = false;

	GrassMeshComp = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("GrassMeshComp"));
	GrassMeshComp->SetupAttachment(RootComponent);
	GrassMeshComp->CastShadow = false;

	bRunConstructionScriptOnDrag = false;

	DestroyTiles();

	Settings = GetMutableDefault<UHexGridSettings>();
	check(Settings);
}

void AHexManager::BeginPlay()
{
	Super::BeginPlay();
}

void AHexManager::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	UHexGridSubsystem* Subsystem = World->GetSubsystem<UHexGridSubsystem>();
	if (!Subsystem)
	{
		return;
	}

	UFastNoiseWrapper* NoiseWrapperLvl1 = Subsystem->NoiseWrapperLvl1;
	if (!NoiseWrapperLvl1)
	{
		return;
	}

	NoiseWrapperLvl1->SetupFastNoise(
		NoiseType,
		Seed,
		Frequency,
		Interp,
		Fractaltype,
		Octaves,
		Lacunarity,
		Gain,
		CellularJitter,
		CellularDistanceFunction,
		CellularReturnType
	);

	if (!NoiseWrapperLvl1->IsInitialized())
	{
		return;
	}

	DestroyTiles();
	HexGridArray.SetNumZeroed(GridWidth);

	for (int32 i = 0; i < HexGridArray.Num(); i++)
	{
		HexGridArray[i].SetNumZeroed(GridHeight);
	}

	for (int32 y = 0; y < GridHeight; y++)
	{
		for (int32 x = 0; x < GridWidth; x++)
		{
			const bool oddRow = y % 2 == 1;
			const float xPos = oddRow ? (x * Settings->TileHorizontalOffset) + Settings->OddRowHorizontalOffset : x * Settings->TileHorizontalOffset;
			const float yPos = y * Settings->TileVerticalOffset;

			UInstancedStaticMeshComponent* currentComp = nullptr;
			float randomHeight = 0;
			float randomNoise = NoiseWrapperLvl1->GetNoise2D(xPos, yPos);

			if (randomNoise >= 0.f)
			{
				currentComp = GrassMeshComp;
				randomHeight = randomNoise;
			}
			else
			{
				currentComp = WaterMeshComp;
				randomHeight = randomNoise * 0.5;
			}

			if (currentComp)
			{
				const FVector spawnLocation = FVector(xPos, yPos, randomHeight * HeightStrength);
				FString debugText = FString::Printf(TEXT("X: %d, Y: %d"), x, y);
				currentComp->AddInstance(FTransform(spawnLocation));

				PersistentDebugInfo.Emplace(debugText, spawnLocation);
			}
		}
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("You have just changed something from inspector."));
}

void AHexManager::DestroyTiles()
{
	if (WaterMeshComp)
	{
		WaterMeshComp->ClearInstances();
	}
	if (GrassMeshComp)
	{
		GrassMeshComp->ClearInstances();
	}

	PersistentDebugInfo.Empty();
}
