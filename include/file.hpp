#pragma once

#include<vector>
#include <iostream>
#include <fstream>
#include "grid.hpp"

class readfile {
public:
    readfile(std::string filename):filename(filename) {}

    std::pair<std::vector<std::vector<int>>, int> Read();

private:
    std::string filename;
};