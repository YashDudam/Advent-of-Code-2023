#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <array>
#include <string>

class Game {
private:
    int game_id_;
    int min_red_;
    int min_green_;
    int min_blue_;

    std::vector<std::array<int, 3>> cube_sets_;
public:
    Game(std::string game_info);
    auto id() const -> int;
    auto is_valid() const -> bool;
    auto minimum_power() -> int;
    ~Game();
};

#endif
