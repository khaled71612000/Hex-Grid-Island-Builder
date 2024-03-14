// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "HexGridSettings.h"
#include "../../../../../../../Plugins/Marketplace/FastNoiseGenerator/Source/FastNoiseGenerator/Public/FastNoiseWrapper.h"

#include "HexManager.generated.h"

struct FDebugInfo
{
	FString Info;
	FVector Location;
};

UCLASS()
class SANDBOX_API AHexManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AHexManager();
protected:

	virtual void BeginPlay() override;

	void DestroyTiles();

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridWidth = 3;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridHeight = 5;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float ChanceOfWater = 0.f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float HeightStrength = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HexGrid|Setup")
	UInstancedStaticMeshComponent* WaterMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HexGrid|Setup")
	UInstancedStaticMeshComponent* GrassMeshComp;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	EFastNoise_NoiseType NoiseType = EFastNoise_NoiseType::Simplex;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	int32 Seed = 1337;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	float Frequency = 0.01f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	EFastNoise_Interp Interp = EFastNoise_Interp::Quintic;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	EFastNoise_FractalType Fractaltype = EFastNoise_FractalType::FBM;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	int32 Octaves = 3;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	float Lacunarity = 2.0f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	float Gain = 0.5f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	float CellularJitter = 0.45f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	EFastNoise_CellularDistanceFunction CellularDistanceFunction = EFastNoise_CellularDistanceFunction::Euclidean;

	UPROPERTY(EditAnywhere, Category = "HexGrid|NoiseLvl1")
	EFastNoise_CellularReturnType CellularReturnType = EFastNoise_CellularReturnType::CellValue;

private:
	virtual void OnConstruction(const FTransform& Transform) override;

	TArray<TArray<AHexTile*>> HexGridArray = {};

	UPROPERTY()
	UHexGridSettings* Settings = nullptr;

	TArray<FDebugInfo> PersistentDebugInfo;

	//UPROPERTY()
	//UFastNoiseWrapper* NoiseWrapperLvl1;
};
