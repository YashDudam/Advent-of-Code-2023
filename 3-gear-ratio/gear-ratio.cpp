#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

auto read_schematic(std::ifstream &file) -> std::vector<std::string>;
auto parse_schematic(std::vector<std::string> schematic) -> std::vector<int>;
auto is_special(char character) -> bool;
auto check_above(std::vector<std::string> schematic, int row, int col) -> bool;
auto check_below(std::vector<std::string> schematic, int row, int col) -> bool;
auto check_left(std::vector<std::string> schematic, int row, int col) -> bool;
auto check_right(std::vector<std::string> schematic, int row, int col) -> bool;
auto check_diagonals(std::vector<std::string> schematic, int row, int col) -> bool;

int main(int const argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "USAGE: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::string filename = argv[1];
    auto file = std::ifstream(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return 1;
    }

    auto schematic = read_schematic(file);
    auto valid_numbers = parse_schematic(schematic);
    auto sum = std::accumulate(valid_numbers.begin(), valid_numbers.end(), 0);

    std::cout << "Sum of part numbers: " << sum << std::endl;

    file.close();
    return 0;
}

auto parse_schematic(std::vector<std::string> schematic) -> std::vector<int> {
    auto valid_numbers = std::vector<int>{};

    std::string num = "";
    auto is_adjacent = false;
    for (int row = 0; row < schematic.size(); row++) {
        for (int col = 0; col < schematic[row].size(); col++) {
            if (!std::isdigit(schematic[row][col])) {
                // add if adjacent special is found and reset variables.
                if (is_adjacent) valid_numbers.push_back(std::stoi(num));
                num = "";
                is_adjacent = false;
                continue;
            }

            // build number
            num += schematic[row][col];

            auto above = check_above(schematic, row, col);
            auto below = check_below(schematic, row, col);
            auto left = check_left(schematic, row, col);
            auto right = check_right(schematic, row, col);
            auto diagonals = check_diagonals(schematic, row, col);

            if (!is_adjacent) {
                is_adjacent = above || below || left || right || diagonals;
            }
        }
    }

    return valid_numbers;
}

auto is_special(char character) -> bool {
    return !(std::isdigit(character) || character == '.');
}

auto check_above(std::vector<std::string> schematic, int row, int col) -> bool {
    if (row == 0) {
        return false;
    }

    return is_special(schematic[row - 1][col]);
}

auto check_below(std::vector<std::string> schematic, int row, int col) -> bool {
    if (row == schematic.size() - 1) {
        return false;
    }

    return is_special(schematic[row + 1][col]);
}

auto check_left(std::vector<std::string> schematic, int row, int col) -> bool {
    if (col == 0) {
        return false;
    }

    return is_special(schematic[row][col - 1]);
}

auto check_right(std::vector<std::string> schematic, int row, int col) -> bool {
    if (col == schematic.size() - 1) {
        return false;
    }

    return is_special(schematic[row][col + 1]);
}

auto check_diagonals(std::vector<std::string> schematic, int row, int col) -> bool {
    if (row != 0 && col != 0) {
        if (is_special(schematic[row - 1][col - 1])) {
            return true;
        }
    }

    if (row != 0 && col != schematic.size() - 1) {
        if (is_special(schematic[row - 1][col + 1])) {
            return true;
        }
    }

    if (row != schematic.size() - 1 && col != 0) {
        if (is_special(schematic[row + 1][col - 1])) {
            return true;
        }
    }

    if (row != schematic.size() - 1 && col != schematic.size() - 1) {
        if (is_special(schematic[row + 1][col + 1])) {
            return true;
        }
    }
    return false;
}


auto read_schematic(std::ifstream &file) -> std::vector<std::string> {
    auto schematic = std::vector<std::string>{};
    std::string line;
    while (std::getline(file, line)) {
        schematic.push_back(line);
    }
    return schematic;
}
