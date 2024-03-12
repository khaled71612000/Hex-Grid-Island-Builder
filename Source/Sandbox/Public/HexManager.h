// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "HexManager.generated.h"

class AHexTile;

UCLASS()
class SANDBOX_API AHexManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AHexManager();
protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridWidth = 0;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	int32 GridHeight = 0;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileHorizontalOffset = 0.f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float oddRowHorizontalOffset = 0.f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Layout")
	float TileVerticalOffset = 0.f;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> GrassTile = nullptr; 

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	TSubclassOf<AHexTile> WaterTile = nullptr;

	UPROPERTY(EditAnywhere, Category = "HexGrid|Setup")
	float ChanceOfWater = 0.f;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HexGrid|Setup")
	//UInstancedStaticMeshComponent* InstanceMeshComp;

private:

	TArray<TArray<AHexTile*>> HexGridArray = {};

	virtual void OnConstruction(const FTransform& Transform) override;
};
