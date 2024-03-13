// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "HexGridSettings.generated.h"


//UENUM()
//enum class EHexTileType : uint8
//{
//	INVALID,
//	GRASS,
//	WATER,
//	MAX UMETA(Hidden)
//};
//
//
//USTRUCT()
//struct FHexTileBody
//{
//	GENERATED_BODY()
//
//	UPROPERTY(VisibleInstanceOnly, Category = "Tile")
//	FIntPoint TileIndex = {};
//
//	UPROPERTY(EditDefaultsOnly, Category = "Tile")
//	EHexTileType TileType = EHexTileType::INVALID;
//
//	UPROPERTY(EditDefaultsOnly, Category = "Tile")
//	UStaticMeshComponent* TileMesh = nullptr;
//};


UCLASS(Config = HexGridSettings, defaultconfig, meta = (DisplayName = "Hex Grid Settings"))
class SANDBOX_API UHexGridSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "HexGrid|Layout")
	float TileHorizontalOffset = 86.602539f;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "HexGrid|Layout")
	float oddRowHorizontalOffset = 43.30127f;

	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "HexGrid|Layout")
	float TileVerticalOffset = 75.0f;
};
