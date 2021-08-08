#include <iostream>
#include <cstdlib>
#include "Easy.h"

void Easy::make_move(Board &board)
{
    int x{0};
    int y{0};
    do
    {
        x = (std::rand() % 3) + 1;
        y = (std::rand() % 3) + 1;
        std::cout << x << '\n';
        std::cout << y << '\n';
        std::cout << board.freeField(x,y) << '\n';
        std::cout << board.getBoard()[x][y] << '\n';

    } while (board.freeField(x, y) && !board.isGameOver());
    board.refresh(x, y,'O');
    // std::cout << x << '\n';
    // std::cout << y << '\n';
}