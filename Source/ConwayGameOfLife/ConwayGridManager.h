#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConwayGridManager.generated.h"

UCLASS()
class CONWAYGAMEOFLIFE_API AConwayGridManager : public AActor
{
	GENERATED_BODY()
	
public:
	AConwayGridManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere, Category= "rules")
	int32 GridSizeX = 10;

	UPROPERTY(EditAnywhere, Category = "rules")
	int32 GridSizeY = 10;

	UPROPERTY(EditAnywhere, Category = "rules")
	int32 GridOffSet = 100;

	UPROPERTY(EditAnywhere, Category = "rules")
	TArray<class AConwayCell*> Grid;

	UPROPERTY(EditAnywhere, Category = "rules")
	TSubclassOf<class AConwayCell> CellTemplate;

	void InitializeGrid();
	void UpdateGrid();
	int32 GetAliveNeighbors(int32 X, int32 Y);
};
