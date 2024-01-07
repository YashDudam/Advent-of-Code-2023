#include <iostream>
#include <fstream>
#include <unordered_map>

int extract_first_digit(std::string line);
int extract_second_digit(std::string line);
int string_to_num(char digit);

int main(int const argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Please provide one filename.\n";
        return 1;
    }
    std::string filename = argv[1];

    auto file = std::ifstream(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    int calibration = 0;
    std::string line;
    while (std::getline(file, line)) {
        int first_digit = extract_first_digit(line);
        int second_digit = extract_second_digit(line);
        calibration += first_digit * 10 + second_digit;
    }
    std::cout << "Calibration: " << calibration << std::endl;

    file.close();

    return 0;
}

int extract_first_digit(std::string line) {
    for (auto const& letter : line) {
        if (std::isdigit(letter)) {
            return string_to_num(letter);
        }
    }

    return -1;
}

int extract_second_digit(std::string line) {
    for (auto iter = line.crbegin(); iter != line.crend(); iter++) {
        char const letter = *iter;
        if (std::isdigit(letter)) {
            return string_to_num(letter);
        }
    }

    return -1;
}

int string_to_num(char digit) {
    return (digit >= '0' && digit <= '9') ? digit - '0' : -1;
}
