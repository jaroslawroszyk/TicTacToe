#include "../include/Game.h"

#include "../include/Easy.h"
//#include "../include/Medium.h"
//#include "../include/Hard.h"

constexpr int movesPerGame = 9;

std::istream &operator>>(std::istream &in , MenuMode &enter)
{
    int int_entry{};
    enter = (in >> int_entry) ? static_cast<MenuMode>(int_entry) : MenuMode::exit;
    return in;
}

auto Game::playerVsPlayer()->void
{
    int i{};
    while (i < movesPerGame)
    {
        i++;
        board.drawBoard();
        if (i % 2 != 0)
        {
            auto [row , col] = board.getUserInput();
            board.refresh(row , col , 'X');
        }
        else
        {
            auto [row , col] = board.getUserInput();
            board.refresh(row , col , 'O');
        }
        char winner = board.checkWinner();
        if (winner == 'X' || winner == 'O')
        {
            board.drawBoard();
            std::cout << winner << " WON!\n";
            board.reset();
            return;
        }
    }
    board.drawBoard();
}

auto Game::playerVsEasyAi()->void
{
    int i{};
    Easy botEasy;
    while (i < movesPerGame)
    {
        i++;
        board.drawBoard();
        if (i % 2 != 0)
        {
            auto [row , col] = board.getUserInput();
            board.refresh(row , col , 'X');
        }
        else
        {
            botEasy.make_move(board);
        }
        char winner = board.checkWinner();
        if (winner == 'X' || winner == 'O')
        {
            board.drawBoard();
            std::cout << winner << " WON!\n";
            board.reset();
            return;
        }
    }
}

auto Game::menu()->void
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
                playerVsPlayer();
                break;
            }
            case MenuMode::player_vs_EasyAi:
            {
                playerVsEasyAi();
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
