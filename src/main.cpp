#include <iostream>
#include <raylib.h>
#include "simulation.hpp"
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "file.hpp"

std::string generate_datetime_filename() {
    std::time_t now = std::time(nullptr);
    std::tm local_tm = *std::localtime(&now);
    std::stringstream ss;
    ss << std::put_time(&local_tm, "%Y%m%d_%H%M%S");
    return ss.str();
}

void initializeWindow(int width, int height, int fps, const std::string& title) {
    InitWindow(width, height, title.c_str());
    SetTargetFPS(fps);
}

int main() {
    const Color Grey = {44, 44, 44, 255};
    const int DEFAULT_WINDOW_SIZE = 750;
    const int DEFAULT_CELL_SIZE = 5;
    const int FPS = 12; // Frames Per Second

    std::string filename;
    std::cout << "Enter filename's Relative Path (or press Enter to skip): ";
    std::getline(std::cin, filename);

    int windowWidth = DEFAULT_WINDOW_SIZE;
    int windowHeight = DEFAULT_WINDOW_SIZE;
    int cellSize = DEFAULT_CELL_SIZE;
    std::vector<std::vector<int>> startPosition;

    if (!filename.empty()) {
        readfile file(filename);
        std::pair<std::vector<std::vector<int>>, int> readOutput = file.Read();
        if (!readOutput.first.empty()) {
            startPosition = readOutput.first;
            cellSize = readOutput.second;
            windowWidth = startPosition[0].size() * cellSize;
            windowHeight = startPosition.size() * cellSize;
        }
    }

    initializeWindow(windowWidth, windowHeight, FPS, "Game of Life");

    Simulation simulation(windowWidth, windowHeight, cellSize, startPosition);

    // Simulation Loop
    while (!WindowShouldClose()) {
        // 1. Event Handling
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mousePosition = GetMousePosition();
            int row = mousePosition.y / cellSize;
            int column = mousePosition.x / cellSize;
            simulation.ToggleCell(row, column);
        }
        if (IsKeyPressed(KEY_ENTER)) {
            simulation.start();
            SetWindowTitle("Game of Life Program is Running...");
        } else if (IsKeyPressed(KEY_SPACE)) {
            simulation.stop();
            SetWindowTitle("Game of Life Program has Stopped!");
        } else if (IsKeyPressed(KEY_C)) {
            std::string filename = "data_" + generate_datetime_filename() + ".txt";
            simulation.write(filename);
        }

        // 2. Updating State
        simulation.Update();

        // 3. Drawing Objects
        BeginDrawing();
        ClearBackground(Grey);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}