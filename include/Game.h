#pragma once

#include "Board.h"
#include <iostream>

enum class MenuMode
{
    player_vs_player = 1 ,
    player_vs_EasyAi = 2 ,
    player_vs_MediumAi = 3 ,
    player_vs_HardAi = 4 ,
    exit = 5 ,
};

class Game
{
public:
    auto playerVsPlayer() -> void;

    auto playerVsEasyAi() -> void;

    auto playerVsMediumAi() -> void;

    auto PlayerVsHardAi() -> void;

    auto menu() -> void;

    //todo getscore count score
    auto getScore() const -> int
    {
        return score;
    }

private:
    Board board;
    int score{};
    bool round{};
};

std::istream &operator>>(std::istream &in , MenuMode &enter);



