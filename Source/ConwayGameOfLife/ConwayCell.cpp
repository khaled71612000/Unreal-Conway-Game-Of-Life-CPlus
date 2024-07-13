#include "ConwayCell.h"

// Sets default values
AConwayCell::AConwayCell()
{
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CellMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CellMesh"));
	RootComponent = CellMesh;

	bIsAlive = false;
}

// Called when the game starts or when spawned
void AConwayCell::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AConwayCell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConwayCell::SetState(bool bNewState)
{
	bIsAlive = bNewState;

	if (bIsAlive)
	{
		//CellMesh->SetVisibility(true);
		CellMesh->SetMaterial(0, AliveMaterial);
	}
	else
	{
		//CellMesh->SetVisibility(false);
		CellMesh->SetMaterial(0, DeadMaterial);
	}
}

bool AConwayCell::GetState() const
{
	return bIsAlive;
}
