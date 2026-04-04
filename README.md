# Unreal Conway Game Of Life CPlus

> Conway's Game of Life in Unreal Engine 5 — interactive cellular automaton displaying cell population evolution on a configurable grid with real-time step controls.

![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-0E1128?logo=unrealengine&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green)

## Overview

Conway's Game of Life in Unreal Engine 5 — interactive cellular automaton displaying cell population evolution on a configurable grid with real-time step controls.

Built with **Unreal Engine** and **C++**, demonstrating professional game development patterns: the Actor-Component model, Unreal's reflection system (UPROPERTY/UFUNCTION), Blueprint interoperability, and optimized gameplay systems.

## Features

- Unreal Engine gameplay framework (GameMode, GameState, PlayerController)
- Custom C++ Actor and Component classes
- Blueprint-C++ interoperability
- Physics and collision systems
- Optimized asset loading

## Technologies Used

| Technology | Details |
|------------|---------|
| Unreal Engine | 4.x / 5.x |
| C++ | Modern C++17 |
| Blueprints | Visual scripting |
| Chaos Physics | Physics simulation |

## Screenshots / Demo

> *No screenshots available yet.*

## Getting Started

### Prerequisites

- [Unreal Engine](https://www.unrealengine.com/en-US/download) 4.x or 5.x
- Visual Studio 2019 or 2022 with **Desktop development with C++**
- Git LFS

### Installation

```bash
git lfs install
git clone https://github.com/khaled71612000/Unreal-Conway-Game-Of-Life-CPlus.git
cd Unreal-Conway-Game-Of-Life-CPlus
```

1. Right-click `.uproject` → **Generate Visual Studio project files**
2. Open `.sln` in Visual Studio
3. Set config: **Development Editor | Win64**
4. Build (Ctrl+Shift+B) then launch the editor

## Project Structure

```
Unreal-Conway-Game-Of-Life-CPlus/
├── Source/                  # C++ source files
  Source/ConwayGameOfLife/ConwayCell.cpp
  Source/ConwayGameOfLife/ConwayCell.h
  Source/ConwayGameOfLife/ConwayGameOfLife.cpp
  Source/ConwayGameOfLife/ConwayGameOfLife.h
  Source/ConwayGameOfLife/ConwayGridManager.cpp
  Source/ConwayGameOfLife/ConwayGridManager.h
├── Content/                 # Assets, blueprints, levels
├── Config/                  # Project settings
└── Unreal-Conway-Game-Of-Life-CPlus.uproject
```

## License

[MIT License](LICENSE)
