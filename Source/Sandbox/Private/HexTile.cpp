#include "HexTile.h"

AHexTile::AHexTile()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComp"));
	TileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TileMesh"));
	TileMesh->SetupAttachment(RootComponent);
}

void AHexTile::BeginPlay()
{
	Super::BeginPlay();
}
