#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HexTile.generated.h"

UENUM()
enum class EHexTileType : uint8
{
	INVALID,
	GRASS,
	WATER,
	MAX UMETA(Hidden)
};

UCLASS()
class SANDBOX_API AHexTile : public AActor
{
	GENERATED_BODY()

public:
	AHexTile();

	UPROPERTY(VisibleInstanceOnly, Category = "Tile")
	FIntPoint TileIndex = {};

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	EHexTileType TileType = EHexTileType::INVALID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Tile")
	UStaticMeshComponent* TileMesh = nullptr;

	virtual void BeginPlay() override;
};
