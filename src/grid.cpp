#include <raylib.h>
#include "grid.hpp"

void Grid::Draw() {
    for (int row=0; row < rows; row++) {
        for (int column  = 0; column < columns; column++) {
            Color color = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255}; //color = {r,g,b,alpha(transparency)}
            DrawRectangle(column * cellSize, row * cellSize ,cellSize - 1, cellSize - 1,color); //drawRect = {x, y, w, h, color}
        }
    }
}

void Grid::SetValue(int row, int column, int value) {
    if (row >= 0 and row < rows and column >= 0 and column < columns) {
        cells[row][column] = value;
    }
}

int Grid::GetValue(int row, int column) {
    if (row >= 0 and row < rows and column >= 0 and column < columns) {
        return cells[row][column];
    } else {
        return 0;
    }
}

void Grid::GenerateRandom() {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            int randomValue = GetRandomValue(0, 4); 
            cells[row][column] = (randomValue == 4) ? 1 : 0; //20% of the grid would be randomly filled
        }
    }
}

void Grid::writefromFile(std::vector<std::vector<int>> matrix) {
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            if (matrix[row][column]) cells[row][column] = 1;
        }
    }
}

void Grid::ToggleCell(int row, int column)
{
    if (row >= 0 and row < rows and column >= 0 and column < columns) {
        cells[row][column] = !cells[row][column];
    }
}