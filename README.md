# Tetramem SW Engineering interview Homework
Implement Conway’s Game Of Life algorithm in C++

## Prerequisites
1. Clone Raylib-QuickStart Repo from https://github.com/raylib-extras/raylib-quickstart
2. Follow README and install Raylib for your Host OS

## Intro
1. The Precompiled Pattern Matrix (To Begin the Game) for Glider and Gosper's Glider Gun can be found and used from the /patterns directory
2. The /src directory has all the C++ code and the game can be built here using the commands showed in the steps below
3. Makefile is only configured to run on MacOS/Linux (with Pre-Reqs installed on root directory of this repo). Very Minimal
3. The Docker Directory is configured to install all the Pre-reqs; but it gets complicated to build a GUI from container to run on your Host Machine. Let's Skip this for some other day! and build the Game through Pre-reqs

## Steps to Run Game of Life

### Linux/MacOS (GCC)
In your root_directory, Run `make` or build using the command below:
```
g++ -Isrc -Iinclude -Iraylib-quickstart -g -std=c++17 -Wall -Lraylib-quickstart src/main.cpp src/file.cpp src/grid.cpp src/simulation.cpp -lraylib -lm -lpthread -ldl -o build/gameOfLife
```

Go to Build Directory and Run the Game
```
cd build
./gameOfLife
```

It will prompt you to choose a pattern option:
1. For Glider Pattern: Type on screen
```
../patterns/glider.txt
```
2. Gosper's Glider Gun: Type on screen
```
../patterns/glider_gun.txt
```
3. Press Enter for Random Game of Life Setup

***Controls***

Once the GUI Opens up, 
1. Press Enter to Start the Game
2. Press Space to Pause the Game
3. Once Paused, You can use Mouse to Make the Cells Alive/Dead
4. Press c to create a timestamp Capture of the Game State that can be used later

### Windows (MinGW GCC)

The Process remains the same as Linux/MacOS. The build command for Windows is shown below (Hopefully this works, Not tested yet!)

```
g++ src\main.cpp src\file.cpp src\grid.cpp src\simulation.cpp -o build\gameOfLife -Isrc -Iinclude -I"C:\path\to\raylib-quickstart" -L"C:\path\to\raylib-quickstart" -lraylib -lopengl32 -lgdi32 -std=c++17 -Wall -g
```


### Misc Notes
1. The Glider and Gosper’s Glider Gun problem has been solved. 
2. States can be saved in file format and retrieved. 
3. I am unclear about representing in sparse format, so I will skip it this time.