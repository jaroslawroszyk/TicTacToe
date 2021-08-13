#include "Game.h"

#include "Easy.h"
#include "Medium.h"
#include "Hard.h"

constexpr int movesPerGame = 9;

std::istream& operator>>(std::istream& in, MenuMode& enter) {
    int int_entry{};
    enter = (in >> int_entry) ? static_cast<MenuMode>(int_entry) : MenuMode::exit;
    return in;
}

void Game::playerVsPlayer() {
    int i{};
    while (i < movesPerGame) {
        i++;
        board.drawBoard();
        auto [row, col, mark] = board.getUserInput();
        board.refresh(row, col, mark);
    }
    board.drawBoard();
}

void Game::playerVsEasyAi() {
    int i{};
    Easy botEasy;
    while (i < movesPerGame) {
        i++;
        board.drawBoard();
        if (i % 2 != 0) {
            auto [row, col, mark] = board.getUserInput();
            if (board.isTaken(row, col)) {
                i--;
            } else {
                board.refresh(row, col, mark);
            }
        } else {
            botEasy.make_move(board);
        }
        char winner = board.checkWinner();
        if (winner == 'X' || winner == 'O') {
            board.drawBoard();
            std::cout << winner << " WON!\n";
            return;
        }
    }
}

void Game::playerVsMediumAi() {
    // int i{};
    // Medium botMedium;
    // while (i < movesPerGame) {
    //     i++;
    //     board.drawBoard();
    //     if (i % 2 != 0) {
    //         auto [row, col, mark] = board.getUserInput();
    //         board.refresh(row, col, mark);
            
    //     } else {
    //         botMedium.make_move(board);
    //     }
    //     char winner = board.checkWinner();
    //     if (winner == 'X' || winner == 'O') {
    //         board.drawBoard();
    //         std::cout << winner << " WON!\n";
    //         return;
    //     }
    // }
}

void Game::PlayerVsHardAi() {
    int i{};
    Hard botHard;
    while (i < movesPerGame) {
        i++;
        board.drawBoard();
        if (i % 2 != 0) {
            auto [row, col, mark] = board.getUserInput();
            board.refresh(row, col, mark);
        } else {
            botHard.make_move(board);
        }
        char winner = board.checkWinner();
        if (winner == 'X' || winner == 'O') {
            board.drawBoard();
            std::cout << winner << " WON!\n";
            return;
        }
    }
}

void Game::menu() {
    MenuMode choose;
    do {
        std::cout << "[1] Player vs Player \n";
        std::cout << "[2] Player vs EasyAi\n";
        std::cout << "[3] Player vs MediumAi\n";
        std::cout << "[4] Player vs HardAi\n";  //algorithm MiniMax
        std::cout << "[5] Exit\n";
        std::cin >> choose;
        switch (choose) {
        case MenuMode::player_vs_player: {
            playerVsPlayer();
            break;
        }
        case MenuMode::player_vs_EasyAi: {
            playerVsEasyAi();
            break;
        }
        case MenuMode::player_vs_MediumAi: {
            playerVsMediumAi();
            break;
        }
        case MenuMode::player_vs_HardAi: {
            PlayerVsHardAi();
            break;
        }
        case MenuMode::exit: {
            break;
        }
        default: {
            std::cout << "Invalid option \n";
            break;
        }
        }
    } while (choose != MenuMode::exit);
}
