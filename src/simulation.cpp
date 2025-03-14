#include "simulation.hpp"

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValue(row, column, value);
}


int Simulation::CountLiveNeighbors(int row, int column) {
    int countAlive = 0;

    /*
    Offset Calculation is done in this order from Top left
    1 -> -> 
    |       |
    |       |
      <- <- 
    */
    std::vector<std::pair<int, int>> offsets = {
        {-1, -1},   // Top left
        {-1, 0},    // Top
        {-1, 1},    // Top right
        {0, 1},     // Right
        {1, 1},     // Bottom Right
        {1, 0},     // Bottom
        {1, -1},    // Bottom Left
        {0, -1}     // Left
    };

    int row_size = grid.GetRows(), column_size = grid.GetColumns();
    for (const auto& offset: offsets) {
        int neighbourRow = (row + offset.first + row_size) % row_size;
        int neighborColumn = (column + offset.second + column_size) % column_size;
        countAlive += grid.GetValue(neighbourRow, neighborColumn);
    }

    return countAlive;

}

void Simulation::Update() {
    if (IsRunning()){
        for (int row = 0; row < grid.GetRows(); row++) {
            for (int column = 0; column < grid.GetColumns(); column++) {
                int aliveNeighbors = CountLiveNeighbors(row, column);
                int cellValue = grid.GetValue(row, column);

                // Game of Life Conditions
                // Any live cell with fewer than two live neighbors dies as if caused by under-population.
                if (cellValue == 1 and aliveNeighbors < 2) temporaryGrid.SetValue(row, column, 0);

                // Any live cell with two or three live neighbors lives on to the next generation.
                else if (cellValue == 1 and (aliveNeighbors == 2 or aliveNeighbors == 3)) temporaryGrid.SetValue(row, column, 1);

                // Any live cell with more than three live neighbors dies, as if by over-population.
                else if (cellValue == 1 and aliveNeighbors > 3) temporaryGrid.SetValue(row, column, 0);

                // Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
                else if (cellValue == 0 and aliveNeighbors == 3) temporaryGrid.SetValue(row, column, 1);
            }
        }
        grid = temporaryGrid;
    }
}

void Simulation::write(std::string filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        int rows = grid.GetRows();
        int columns = grid.GetColumns();
        int cells = grid.GetCellSize();
        // Write the number of rows and columns as strings
        file << rows << " " << columns << " " << cells << "\n";

        // Write each element of the matrix
        for (int row = 0; row < rows; row++) {
            for (int column = 0; column < columns; column++) {
                file << grid.GetValue(row,column);
            }
            file << "\n"; //Newline after each row
        }
        file.close();
    } else {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }
}

void Simulation::ToggleCell(int row, int column)
{
    if(!IsRunning())
    {
        grid.ToggleCell(row, column);
    }
}