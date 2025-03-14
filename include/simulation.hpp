#pragma once
#include "grid.hpp"
#include "file.hpp"

class Simulation
{
    public:
        Simulation(int width, int height, int cellsize, std::vector<std::vector<int>> matrix) : \
            grid(width, height, cellsize), temporaryGrid(width, height, cellsize), matrix(matrix), run(false) 
        {    
            if (matrix.empty()) {
                grid.GenerateRandom();
            } else {
                grid.writefromFile(matrix);
            }
        };
        
        void Draw();

        void SetCellValue(int row, int column, int value);

        int CountLiveNeighbors(int row, int column);

        void Update();

        void write(std::string filename);

        bool IsRunning() { 
            return run; 
        }
        
        void start() {
            run = true;
        }

        void stop() {
            run = false; 
        }

        void ToggleCell(int row, int column);

    private:
        Grid grid;
        Grid temporaryGrid;
        std::vector<std::vector<int>> matrix;
        bool run;
};
