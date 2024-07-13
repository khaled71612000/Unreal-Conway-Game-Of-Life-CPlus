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

};
