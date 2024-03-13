// Fill out your copyright notice in the Description page of Project Settings.


#include "HexManager.h"
#include "HexTile.h"
#include "DrawDebugHelpers.h"

AHexManager::AHexManager()
{
	//TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	//TileMesh->SetupAttachment(RootComponent);

	PrimaryActorTick.bCanEverTick = true;
	bRunConstructionScriptOnDrag = false;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	WaterMeshComp = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("WaterMeshComp"));
	WaterMeshComp->SetupAttachment(RootComponent);
	GrassMeshComp = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("GrassMeshComp"));
	GrassMeshComp->SetupAttachment(RootComponent);
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

			/*
			odd r -> shift row by size to the right or by oddRowHorizontalOffset on the X axis starting second row
			even r shift row by size to the right or by oddRowHorizontalOffset on the X axis starting first row
			odd q shift col by size to the up or by oddColHorizontalOffset on the Y axis starting first row
			even q shift col by size to the up or by oddColHorizontalOffset on the Y axis starting second row
			*/

			const bool oddRow = y % 2 == 1;
			const float xPos = oddRow ? (x * Settings->TileHorizontalOffset) + Settings->oddRowHorizontalOffset : x * Settings->TileHorizontalOffset;
			const float yPos = y * Settings->TileVerticalOffset;

			UInstancedStaticMeshComponent* currentComp = nullptr;
			float randomHeight = 0;

			if (FMath::RandRange(1.f, 100.f) > ChanceOfWater)
			{
				currentComp = GrassMeshComp;
				randomHeight = 1;
			}
			else
			{
				currentComp = WaterMeshComp;
				randomHeight = -1;
			}


			if (currentComp)
			{
				const FVector spawnLocation = FVector(xPos, yPos, randomHeight * HeightStrength);
				FString debugText = FString::Printf(TEXT("X: %d, Y: %d"), x, y);
				currentComp->AddInstance(FTransform(spawnLocation));

				PersistentDebugInfo.Emplace(debugText, spawnLocation);
			}
			//if (newTile)
			//{
			/*newTile->TileIndex = FIntPoint(x, y);
			newTile->SetActorLabel(FString::Printf(TEXT("%d- %d"), x, y));
			HexGridArray[x][y] = newTile;*/
			//}
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("You have just changed something from inspector."));
}

void AHexManager::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	for (const FDebugInfo& DebugInfo : PersistentDebugInfo)
	{
		DrawDebugString(GetWorld(), DebugInfo.Location, DebugInfo.Info, nullptr, FColor::White, -1.f);
	}
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
