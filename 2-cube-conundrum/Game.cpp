#include <iostream>
#include <regex>

#include "Game.hpp"

#define RED_MAX 12
#define GREEN_MAX 13
#define BLUE_MAX 14

#define RED_INDEX 0
#define GREEN_INDEX 1
#define BLUE_INDEX 2

auto tokenize(std::string str, std::string del = " ") -> std::vector<std::string>;
auto build_count(std::string str) -> std::array<int, 3>;

Game::Game(std::string game_info) {
    auto pattern = std::regex("Game ([0-9]+):");
    auto match = std::smatch();
    std::regex_search(game_info, match, pattern);
    game_id_ = std::stoi(match[1].str());

    auto set_info = tokenize(game_info, ": ")[1];
    for (auto &set : tokenize(set_info, "; ")) {
        cube_sets_.push_back(build_count(set));
    }
}

auto Game::id() const -> int {
    return game_id_;
}

auto Game::is_valid() const -> bool {
    for (auto set : cube_sets_) {
        if (set[RED_INDEX] > RED_MAX) return false;
        if (set[GREEN_INDEX] > GREEN_MAX) return false;
        if (set[BLUE_INDEX] > BLUE_MAX) return false;
    }

    return true;
}

Game::~Game() {
}

auto tokenize(std::string str, std::string del) -> std::vector<std::string> {
    auto tokens = std::vector<std::string>();
    int start, end = -1 * del.size();
    do {
        start = end + del.size();
        end = str.find(del, start);
        std::string token = str.substr(start, end - start);
        tokens.push_back(token);
    } while (end != -1);

    return tokens;
}

auto build_count(std::string str) -> std::array<int, 3> {
    auto count = std::array<int, 3>{ -1, -1, -1 };

    for (auto &pair : tokenize(str, ", ")) {
        auto tokens = tokenize(pair);
        auto colour_count = std::stoi(tokens[0]);
        auto colour = tokens[1];
        if (colour == "red") {
            count[RED_INDEX] = colour_count;
        } else if (colour == "green") {
            count[GREEN_INDEX] = colour_count;
        } else { // colour == "blue"
            count[BLUE_INDEX] = colour_count;
        }
    }

    return count;
}
