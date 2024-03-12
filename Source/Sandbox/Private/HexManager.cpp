// Fill out your copyright notice in the Description page of Project Settings.


#include "HexManager.h"
#include "HexTile.h"

AHexManager::AHexManager()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	//TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	//TileMesh->SetupAttachment(RootComponent);
}

void AHexManager::BeginPlay()
{
	Super::BeginPlay();
	
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

			const float xPos = oddRow ? (x * TileHorizontalOffset) + oddRowHorizontalOffset : x * TileHorizontalOffset;
			const float yPos = y * TileVerticalOffset;

			TSubclassOf<AHexTile> tileToSpawn;

			if (FMath::RandRange(1.f, 100.f) > ChanceOfWater)
			{
				tileToSpawn = GrassTile;
			}
			else
			{
				tileToSpawn = WaterTile;
			}


			AHexTile* const newTile = GetWorld()->SpawnActor<AHexTile>(tileToSpawn, FVector(FIntPoint(xPos, yPos)), FRotator::ZeroRotator);
			if (newTile)
			{
				newTile->TileIndex = FIntPoint(x, y);
				newTile->SetActorLabel(FString::Printf(TEXT("%d- %d"), x, y));
				HexGridArray[x][y] = newTile;
			}
		}
	}
}

void AHexManager::OnConstruction(const FTransform& Transform)
{
	//// We initialized in the body instead of constructor.
	//InstanceMeshComp = NewObject<UInstancedStaticMeshComponent>(this);
	//InstanceMeshComp->RegisterComponent();
	//InstanceMeshComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//InstanceMeshComp->SetStaticMesh(GrassTile->GetDefaultObject());
	//InstanceMeshComp->AddInstance(FTransform());
	//UE_LOG(LogTemp, Warning, TEXT("You have just changed something from inspector."));
}
