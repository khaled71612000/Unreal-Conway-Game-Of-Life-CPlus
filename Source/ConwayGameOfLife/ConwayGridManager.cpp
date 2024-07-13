#include "ConwayGridManager.h"
#include "ConwayCell.h"

AConwayGridManager::AConwayGridManager()
{
	PrimaryActorTick.bCanEverTick = true;

	GridSizeX = 10;
	GridSizeY = 10;
}

void AConwayGridManager::BeginPlay()
{
	Super::BeginPlay();
	InitializeGrid();
}

void AConwayGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateGrid();
}

void AConwayGridManager::InitializeGrid()
{
	for (int32 X = 0; X < GridSizeX; X++)
	{
		for (int32 Y = 0; Y < GridSizeY; Y++)
		{
			AConwayCell* NewCell = GetWorld()->SpawnActor<AConwayCell>(CellTemplate, FVector(X * GridOffSet, Y * GridOffSet, 0), FRotator::ZeroRotator);
			Grid.Add(NewCell);
		}
	}
}

void AConwayGridManager::UpdateGrid()
{
	//You need two arrays, old one you have or a new one every frame but of course thats bad.
	//The idea is that you cant change the state of one then measure the other you need to do all at once

	TArray<bool> newStates;
	newStates.SetNum(GridSizeX * GridSizeY);

	for (int32 x = 0; x < GridSizeX; x++)
	{
		for (int32 y = 0; y < GridSizeY; y++)
		{
			int32 index = x + y * GridSizeX;
			int32 aliveNeighbors = GetAliveNeighbors(x, y);

			if (Grid[index]->GetState())
			{
				newStates[index] = aliveNeighbors == 2 || aliveNeighbors == 3;
			}
			else
			{
				newStates[index] = aliveNeighbors == 3;
			}
		}
	}


	// Override old states with new ones
	for (int32 index = 0; index < Grid.Num(); index++)
	{
		Grid[index]->SetState(newStates[index]);
	}
}

int32 AConwayGridManager::GetAliveNeighbors(int32 X, int32 Y)
{
	int32 AliveCount = 0;

	for (int32 OffsetX = -1; OffsetX <= 1; OffsetX++)
	{
		for (int32 OffsetY = -1; OffsetY <= 1; OffsetY++)
		{
			if (OffsetX == 0 && OffsetY == 0)
			{
				continue;
			}

			int32 NeighborX = X + OffsetX;
			int32 NeighborY = Y + OffsetY;

			if (NeighborX >= 0 && NeighborX < GridSizeX && NeighborY >= 0 && NeighborY < GridSizeY)
			{
				int32 NeighborIndex = NeighborX + NeighborY * GridSizeX;
				if (Grid[NeighborIndex]->GetState())
				{
					AliveCount++;
				}
			}
		}
	}

	return AliveCount;
}
