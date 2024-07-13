#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConwayCell.generated.h"

UCLASS()
class CONWAYGAMEOFLIFE_API AConwayCell : public AActor
{
	GENERATED_BODY()
	
public:
	AConwayCell();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SetState(bool bNewState);
	bool GetState() const;

private:
	UPROPERTY(EditAnywhere, Category = "Game Of Life")
	bool bIsAlive = false;

	UPROPERTY(EditAnywhere, Category = "Game Of Life")
	UStaticMeshComponent* CellMesh;

	UPROPERTY(EditAnywhere, Category = "Game Of Life")
	UMaterialInterface* AliveMaterial;

	UPROPERTY(EditAnywhere, Category = "Game Of Life")
	UMaterialInterface* DeadMaterial;

	UPROPERTY(EditAnywhere, Category = "Game Of Life")
	UMaterialInstanceDynamic* DynamicMaterial;

	UPROPERTY(EditAnywhere, Category = "Game Of Life")
	float Health = 1.0f; // 1.0f represents fully alive, 0.0f represents fully dead

};
