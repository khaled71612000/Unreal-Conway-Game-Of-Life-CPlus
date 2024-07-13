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

	UFUNCTION(BlueprintCallable, Category = "Game Of Life")
	void StartSimulation();

	UFUNCTION(BlueprintCallable, Category = "Game Of Life")
	void StopSimulation();

	UFUNCTION(BlueprintCallable, Category = "Game Of Life")
	void ResetSimulation();

	UFUNCTION(BlueprintCallable, Category = "Game Of Life")
	int32 GetGenerationCount () const { return GenerationCount;};
	UFUNCTION(BlueprintCallable, Category = "Game Of Life")
	int32 GetAliveCellsCount() const { return AliveCellsCount; };

	UPROPERTY(EditAnywhere, Category = "rules")
	int32 GenerationCount = 0;

	UPROPERTY(EditAnywhere, Category = "rules")
	int32 AliveCellsCount = 0;

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

	FTimerHandle UpdateTimerHandle;
	UPROPERTY(EditAnywhere, Category = "rules")
	float UpdateInterval = 1.0f; // Update every second
};
