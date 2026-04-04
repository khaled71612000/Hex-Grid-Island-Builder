![6](https://github.com/khaled71612000/Hex-Grid-Island-Builder/assets/59780800/88cc4501-f635-45b3-89dd-985c1232f028)

# Hex Grid Island Builder


![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-0E1128?logo=unrealengine&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green)

**Hex Grid Island Builder** is an advanced project developed using Unreal Engine, designed to create a grid-based island-building game. This project leverages procedural generation using Perlin noise and features a dynamic, interactive environment with hexagonal grid tiles.
![download](https://github.com/user-attachments/assets/f3b4a449-98ca-473b-b787-665ff8416430)


## Live Demo

[![Watch Gameplay Demo](https://img.youtube.com/vi/gF-XHie0oZw/maxresdefault.jpg)](https://youtu.be/gF-XHie0oZw)

> Click the thumbnail above to watch the full demo video.

## Key Components

### Plugins
- **Phoinix RTS Camera Plugin:** Implements a real-time strategy camera system for better control and navigation.

### Source

#### HexGridSubsystem.cpp
- **Subsystem Initialization:** Initializes noise generation for procedural content.
- **Noise Wrapper:** Sets up the noise wrapper for use in terrain generation.

#### HexTile.cpp
- **Tile Setup:** Initializes components for hexagonal tiles.
- **Begin Play:** Handles actions to take when the game starts.

#### HexManager.cpp
- **Grid Management:** Manages the creation and interaction of hexagonal grid tiles.
- **Procedural Generation:** Uses Perlin noise to dynamically generate and place tiles based on noise values.
- **Tile Destruction:** Handles the removal of existing tiles when necessary.

## Features

- **Grid-Based Building:** Implements a hexagonal grid system for placing and managing island tiles.
- **Procedural Generation:** Uses Perlin noise to dynamically generate islands and landmasses, shaping them into hexagonal instances.
- **Interactive Environment:** Allows players to interact with the grid and build their own islands.
- **Advanced Noise Configuration:** Configures noise settings such as frequency, interpolation, and fractal type to create varied terrain.
- **Debug Information:** Provides on-screen debug messages for real-time feedback during development.

## References
- Red Blob Games: [Hexagonal Grids](https://www.redblobgames.com/grids/hexagons/)

This project serves as an excellent example for developers looking to create interactive and dynamic grid-based games using Unreal Engine, highlighting the use of procedural generation and advanced game development techniques.
[YouTube Video](https://youtu.be/gF-XHie0oZw?si=bf95pC5VOy85UbZg)


![WhatsApp Image 2024-06-18 at 19 12 07_770bb84f](https://github.com/khaled71612000/Grid-island-builder/assets/59780800/62687851-a69f-4842-af90-483244dae448)
![image](https://github.com/khaled71612000/Hex-Grid-Island-Builder/assets/59780800/f3f7b843-c2fd-4d04-84e5-787814b309ba)
![image](https://github.com/khaled71612000/Hex-Grid-Island-Builder/assets/59780800/cc0612da-0416-42df-9a0e-cbfbf5253d12)
![image](https://github.com/khaled71612000/Hex-Grid-Island-Builder/assets/59780800/21e65f14-aae2-4a3d-bb72-cf7d105f7277)
![image](https://github.com/khaled71612000/Hex-Grid-Island-Builder/assets/59780800/57245689-1f91-412c-bda5-4c7d26fabb49)


## Screenshots

![Screenshot 1](https://raw.githubusercontent.com/khaled71612000/Hex-Grid-Island-Builder/HEAD/PhotoR_Backgrounds.png)


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
git clone https://github.com/khaled71612000/Hex-Grid-Island-Builder.git
```
1. Right-click the `.uproject` → **Generate Visual Studio project files**
2. Open `.sln` → Build (**Development Editor | Win64**)
3. Launch via Unreal Editor
