#include <iostream>
#include <fstream>
#include <regex>
#include <unordered_map>
#include <vector>
#include <string>

auto extract_first_digit(std::string line) -> int;
auto extract_last_digit(std::string line) -> int;
auto string_to_num(std::string line) -> int;
auto reverse(std::string line) -> std::string;

int main(int const argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Please enter one filename." << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    auto file = std::ifstream(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    auto calibration = 0;
    std::string line;
    while (std::getline(file, line)) {
        int first_digit = extract_first_digit(line);
        int last_digit = extract_last_digit(line);

        calibration += first_digit * 10 + last_digit;
    }
    std::cout << "Calibration: " << calibration << std::endl;

    return 0;
}


auto extract_first_digit(std::string line) -> int {
    auto pattern = std::regex("one|two|three|four|five|six|seven|eight|nine|[0-9]");
    auto match = std::smatch();
    std::regex_search(line, match, pattern);
    return string_to_num(match.str());
}

auto extract_last_digit(std::string line) -> int {
    // reverse the string, then match for the reversed form of digit.
    auto pattern = std::regex("enin|thgie|neves|xis|evif|ruof|eerht|owt|eno|[0-9]");
    std::string reversed = reverse(line);
    auto match = std::smatch();
    std::regex_search(reversed, match, pattern);
    return string_to_num(reverse(match.str()));
}

/**
 * Map strings to their lexical value
 * Throws an exception if value was not found.
*/
auto string_to_num(std::string line) -> int {
    auto numbers = std::unordered_map<std::string, int>{
        { "one", 1 },
        { "two", 2 },
        { "three", 3 },
        { "four", 4 },
        { "five", 5 },
        { "six", 6 },
        { "seven", 7 },
        { "eight", 8 },
        { "nine", 9 },
        { "1", 1 },
        { "2", 2 },
        { "3", 3 },
        { "4", 4 },
        { "5", 5 },
        { "6", 6 },
        { "7", 7 },
        { "8", 8 },
        { "9", 9 }
    };

    return numbers.at(line);
}

/**
 * Reverses a string
*/
auto reverse(std::string line) -> std::string {
    std::string reversed = "";
    for (auto iter = line.crbegin(); iter != line.crend(); iter++) {
        auto const letter = *iter;
        reversed += letter;
    }
    return reversed;
}
