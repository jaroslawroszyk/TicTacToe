#pragma once
#include <iostream>
#include <fstream>
//TODO:
//1. Menu wyboru sekcji gry
//-Gracz vs Gracz
//-Gracz vs EasyAi
//-Gracz vs MediumAi
//-Gracz vs Hard Ai

enum class MenuMode
{
    player_vs_player = 1,
    player_vs_EasyAi = 2,
    player_vs_MediumAi = 3,
    player_vs_HardAi = 4,
    exit = 5,
};

void menu();
std::istream &operator>>(std::istream &in,MenuMode &enter);