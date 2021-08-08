#include <iostream>
#include "TictactoeMode.h"

std::istream &operator>>(std::istream &in, MenuMode &enter)
{
    int int_entry{};
    enter = (in >> int_entry) ? static_cast<MenuMode>(int_entry) : MenuMode::exit;
    return in;
}

void menu()
{
    MenuMode choose;
    do
    {
        std::cout << "[1] Player vs Player \n";
        std::cout << "[2] Player vs EasyAi\n";
        std::cout << "[3] Player vs MediumAi\n";
        std::cout << "[4] Player vs HardAi\n"; //algorithm MiniMax

        std::cout << "[5] Exit\n";
        std::cin >> choose;
        switch (choose)
        {
        case MenuMode::player_vs_player:
        {
            break;
        }
        case MenuMode::player_vs_EasyAi:
        {
            break;
        }
        case MenuMode::player_vs_MediumAi:
        {
            break;
        }
        case MenuMode::player_vs_HardAi:
        {
            break;
        }
        case MenuMode::exit:
        {
            break;
        }
        default:
        {
            std::cout << "Invalid option \n";
            break;
        }
        }
    } while (choose != MenuMode::exit);
}