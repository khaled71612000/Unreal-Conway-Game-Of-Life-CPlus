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

	GetWorld()->GetTimerManager().SetTimer(UpdateTimerHandle, this, &AConwayGridManager::UpdateGrid, UpdateInterval, true);
}

void AConwayGridManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConwayGridManager::InitializeGrid()
{
	Grid.Empty();

	for (int32 X = 0; X < GridSizeX; X++)
	{
		for (int32 Y = 0; Y < GridSizeY; Y++)
		{
			AConwayCell* NewCell = GetWorld()->SpawnActor<AConwayCell>(CellTemplate, FVector(X * GridOffSet, Y * GridOffSet, 0), FRotator::ZeroRotator);
			Grid.Add(NewCell);

			// Initialize some cells as alive for testing
			if (FMath::RandRange(0, 1) == 1)
			{
				NewCell->SetState(true);
			}
		}
	}
}

void AConwayGridManager::StartSimulation()
{
	GetWorld()->GetTimerManager().SetTimer(UpdateTimerHandle, this, &AConwayGridManager::UpdateGrid, UpdateInterval, true);
}

void AConwayGridManager::StopSimulation()
{
	GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);
}

void AConwayGridManager::ResetSimulation()
{
	GetWorld()->GetTimerManager().ClearTimer(UpdateTimerHandle);
	InitializeGrid();
	StartSimulation();
	GenerationCount = 0;
}

void AConwayGridManager::UpdateGrid()
{
	//You need two arrays, old one you have or a new one every frame but of course thats bad.
	//The idea is that you cant change the state of one then measure the other you need to do all at once

	TArray<bool> newStates;
	newStates.SetNum(GridSizeX * GridSizeY);

	AliveCellsCount = 0;

	for (int32 x = 0; x < GridSizeX; x++)
	{
		for (int32 y = 0; y < GridSizeY; y++)
		{
			int32 index = x + y * GridSizeX;
			int32 aliveNeighbors = GetAliveNeighbors(x, y);

			/*
			
			If the cell is alive(Grid[index]->GetState() returns true) :

				The cell remains alive if it has 2 or 3 alive neighbors
				Otherwise, it dies.

				If the cell is dead : The cell becomes alive if it has exactly 3 alive neighbors(aliveNeighbors == 3).
				Otherwise, it remains dead.
			*/

			if (Grid[index]->GetState())
			{
				newStates[index] = aliveNeighbors == 2 || aliveNeighbors == 3;
				if (newStates[index]) AliveCellsCount++;
			}
			else
			{
				newStates[index] = aliveNeighbors == 3;
				if (newStates[index]) AliveCellsCount++;
			}
		}
	}


	// Override old states with new ones
	for (int32 index = 0; index < Grid.Num(); index++)
	{
		Grid[index]->SetState(newStates[index]);
	}

	GenerationCount++;
}

int32 AConwayGridManager::GetAliveNeighbors(int32 X, int32 Y)
{
	int32 AliveCount = 0;

	//you could also count all 8 negh manually lol
	for (int32 OffsetX = -1; OffsetX <= 1; OffsetX++)
	{
		for (int32 OffsetY = -1; OffsetY <= 1; OffsetY++)
		{
			///avoid yourself
			if (OffsetX == 0 && OffsetY == 0)
			{
				continue;
			}

			int32 NeighborX = X + OffsetX;
			int32 NeighborY = Y + OffsetY;

			//dont go over grid size or under
			if (NeighborX >= 0 && NeighborX < GridSizeX && NeighborY >= 0 && NeighborY < GridSizeY)
			{
				//In a 2D grid stored in a 1D array, the index of a cell at position (X, Y) can be calculated using the formula: xindex + yindex * col num
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
