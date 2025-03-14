#include <fstream>
#include "file.hpp"
#include <string>
#include <vector>

std::pair<std::vector<std::vector<int>>, int> readfile::Read() {
    
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }

    int rows, cols, cells;
    file >> rows >> cols >> cells; // Read the dimensions of the matrix

    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

    std::string line;
    for (int i = 0; i < rows; ++i) {
        file >> line; // Read each line of the matrix
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = line[j] - '0'; // Convert char to int
        }
    }

    file.close();

    std::pair<std::vector<std::vector<int>>, int> readOutput = \
        std::make_pair(matrix, cells);

    /*
    // Output the matrix to verify
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
    */

    return readOutput;
 }

