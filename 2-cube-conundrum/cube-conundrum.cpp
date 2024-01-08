#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Game.hpp"

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

    auto sum = 0;
    std::string line;
    while (std::getline(file, line)) {
        auto const game = Game(line);
        if (game.is_valid()) {
            sum += game.id();
        }
    }

    std::cout << "Sum: " << sum << std::endl;

    file.close();

    return 0;
}
