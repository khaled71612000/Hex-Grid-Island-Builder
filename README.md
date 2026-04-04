# Hex Grid Island Builder

> A hexagonal grid-based island builder in Unreal Engine featuring tile placement, procedural terrain generation, and interactive construction gameplay.

![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-0E1128?logo=unrealengine&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?logo=c%2B%2B&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green)

## Overview

A hexagonal grid-based island builder in Unreal Engine featuring tile placement, procedural terrain generation, and interactive construction gameplay.

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

![Screenshot 1](https://raw.githubusercontent.com/khaled71612000/Hex-Grid-Island-Builder/HEAD/PhotoR_Backgrounds.png)

![Screenshot 2](https://raw.githubusercontent.com/khaled71612000/Hex-Grid-Island-Builder/HEAD/Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Resources/Icon128.png)

![Screenshot 3](https://raw.githubusercontent.com/khaled71612000/Hex-Grid-Island-Builder/HEAD/Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Resources/Input-Nodes.png)

![Screenshot 4](https://raw.githubusercontent.com/khaled71612000/Hex-Grid-Island-Builder/HEAD/Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Resources/discord-logo-blue.png)

## Getting Started

### Prerequisites

- [Unreal Engine](https://www.unrealengine.com/en-US/download) 4.x or 5.x
- Visual Studio 2019 or 2022 with **Desktop development with C++**
- Git LFS

### Installation

```bash
git lfs install
git clone https://github.com/khaled71612000/Hex-Grid-Island-Builder.git
cd Hex-Grid-Island-Builder
```

1. Right-click `.uproject` → **Generate Visual Studio project files**
2. Open `.sln` in Visual Studio
3. Set config: **Development Editor | Win64**
4. Build (Ctrl+Shift+B) then launch the editor

## Project Structure

```
Hex-Grid-Island-Builder/
├── Source/                  # C++ source files
  Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Source/rts_camera/Private/RTSPawn.cpp
  Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Source/rts_camera/Private/rts_camera.cpp
  Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Source/rts_camera/Public/RTSPawn.h
  Plugins/Phoinix RTS Camera Plugin 5.3-1.1.1/Source/rts_camera/Public/rts_camera.h
  Source/Sandbox/Private/HexGridSubsystem.cpp
  Source/Sandbox/Private/HexManager.cpp
├── Content/                 # Assets, blueprints, levels
├── Config/                  # Project settings
└── Hex-Grid-Island-Builder.uproject
```

## License

[MIT License](LICENSE)
