![image](https://github.com/user-attachments/assets/c9e8f084-7ea9-411b-a7aa-8e49c8cffd65)
# Conway's Game of Life Project


![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-0E1128?logo=unrealengine&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green)


## Live Demo

[![Watch Gameplay Demo](https://img.youtube.com/vi/strNtTR_IoU/maxresdefault.jpg)](https://youtu.be/strNtTR_IoU)

> Click the thumbnail above to watch the full demo video.

## Overview

This project implements Conway's Game of Life using Unreal Engine. The simulation displays the evolution of cells on a grid based on simple rules, providing a visual representation of the changes in cell states over time.
![GIF 1](https://media.giphy.com/media/frTLRXHIU6AEzBG2Mp/giphy.gif)
## Classes

### AConwayCell

The `AConwayCell` class represents each cell in the Game of Life grid. It manages the state of the cell (alive or dead) and updates the visual representation accordingly.

#### Key Methods
- `SetState(bool bNewState)`: Sets the state of the cell.
- `GetState() const`: Returns the current state of the cell.

### AConwayGridManager

The `AConwayGridManager` class manages the entire grid of cells, controlling the simulation's start, stop, and reset functionality. It updates the grid based on the rules of Conway's Game of Life.

#### Key Methods
- `StartSimulation()`: Starts the simulation.
- `StopSimulation()`: Stops the simulation.
- `ResetSimulation()`: Resets the simulation to its initial state.
- `InitializeGrid()`: Initializes the grid with cell objects.
- `UpdateGrid()`: Updates the grid based on the rules of the Game of Life.
- `GetAliveNeighbors(int32 X, int32 Y)`: Returns the count of alive neighbors for a given cell.

## Features

- **Real-time Simulation**: Updates and renders the cell states in real-time.
- **User Interaction**: Allows users to start, stop, and reset the simulation.
- **Adjustable Parameters**: Grid size and update interval can be adjusted.
- **Visual Representation**: Displays the alive and dead states of cells with different materials.

## Credits

This project is inspired by Conway's Game of Life, a cellular automaton devised by mathematician John Conway. Special thanks to the Unreal Engine community for their support and resources. Additional patterns and information are credited to the [Life Patterns Archive](https://www.ibiblio.org/lifepatterns/october1970.html).

[YouTube Video](https://youtu.be/strNtTR_IoU?si=PYeBxpQX7MS1vYKb)

![image](https://github.com/user-attachments/assets/0ee4fe08-9bee-4022-8b36-9aa985fa8a24)
![image](https://github.com/user-attachments/assets/f084894c-36a8-41f2-bb2f-e5ebaeb85e89)






## Architecture

Key classes and systems (from source code):

- **`ConwayGameOfLife`** (extends `ModuleRules`) — core game class
- **`ConwayGameOfLifeTarget`** (extends `TargetRules`) — core game class
- **`ConwayGameOfLifeEditorTarget`** (extends `TargetRules`) — core game class


## Tech Stack

| Technology | Role |
|---|---|
| Unreal Engine 4/5 | Game engine (Blueprints + C++) |
| C++ | Gameplay systems, custom components |
| HLSL / USF | Custom shader authoring |
| Git LFS | Large asset version control |


## Getting Started

### Prerequisites
- [Unreal Engine](https://www.unrealengine.com/en-US/download) 4.x or 5.x
- Visual Studio 2019 or 2022 with **Desktop development with C++**
- Git LFS (`git lfs install`)

### Setup
```bash
git lfs install
git clone https://github.com/khaled71612000/Unreal-Conway-Game-Of-Life-CPlus.git
```
1. Right-click the `.uproject` → **Generate Visual Studio project files**
2. Open `.sln` → Build (**Development Editor | Win64**)
3. Launch via Unreal Editor
