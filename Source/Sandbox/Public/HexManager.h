// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "HexGridSettings.h"
#include "HexManager.generated.h"

struct FDebugInfo
{
	FString Info;
	FVector Location;
};

class AHexTile;

UCLASS()
class SANDBOX_API AHexManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AHexManager();
protected:

	virtual void BeginPlay() override;
	void Tick(float DeltaSeconds) override;

	void DestroyTiles();

	UPROPERTY(EditInstanceOnly, Category = "HexGrid|Layout")
	int32 GridWidth = 3;

	UPROPERTY(EditInstanceOnly, Category = "HexGrid|Layout")
	int32 GridHeight = 5;

	UPROPERTY(EditInstanceOnly, Category = "HexGrid|Setup")
	float ChanceOfWater = 0.f;

	UPROPERTY(EditInstanceOnly, Category = "HexGrid|Setup")
	float HeightStrength = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HexGrid|Setup")
	UInstancedStaticMeshComponent* WaterMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HexGrid|Setup")
	UInstancedStaticMeshComponent* GrassMeshComp;

private:
	virtual void OnConstruction(const FTransform& Transform) override;

	TArray<TArray<AHexTile*>> HexGridArray = {};
	UHexGridSettings* Settings = nullptr;

	TArray<FDebugInfo> PersistentDebugInfo;
};
