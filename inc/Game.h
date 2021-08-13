#pragma once
#include "Board.h"
#include <iostream>

enum class MenuMode
{
    player_vs_player = 1,
    player_vs_EasyAi = 2,
    player_vs_MediumAi = 3,
    player_vs_HardAi = 4,
    exit = 5,
};



class Game
{
public:
    void playerVsPlayer();
    void playerVsEasyAi();
    void playerVsMediumAi();
    void PlayerVsHardAi();
    void menu();
    //todo getscore count score
    int getScore() const
    {
        return score;
    }
private:
    Board board;
    int score{};
    bool round{};
};

std::istream &operator>>(std::istream &in, MenuMode &enter);



