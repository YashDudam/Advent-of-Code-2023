#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Game.hpp"

#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14

int main(int const argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "USAGE: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    auto const filename = static_cast<std::string>(argv[1]);
    auto file = std::ifstream(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
        break;
    }

    return 0;
}
