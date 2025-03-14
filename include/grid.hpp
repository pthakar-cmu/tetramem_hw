#pragma once

#include<vector>
#include <iostream>


class Grid {
    public:
        Grid(int width, int height, int cellSize): 
            rows(height/cellSize), columns(width/cellSize), cellSize(cellSize), \
            cells(rows, std::vector<int>(columns, 0)) {};

        void Draw();

        void writefromFile(std::vector<std::vector<int>> matrix);

        void SetValue(int row, int column, int value);

        int GetValue(int row, int column);

        int GetRows() { return rows; }
        int GetColumns() { return columns; }
        int GetCellSize() { return cellSize; }

        void GenerateRandom();
        void ToggleCell(int row, int column);

    private:
        int rows;
        int columns;
        int cellSize;
        std::vector<std::vector<int>> cells;
};