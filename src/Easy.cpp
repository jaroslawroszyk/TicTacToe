#include <iostream>
#include <cstdlib>
#include "Easy.h"

void Easy::make_move(Board &board)
{
    int x{};
    int y{};
    do
    {
        x = std::rand() % 3;
        y = std::rand() % 3;
    
    } while (!board.freeField(x,y) && board.isGameOver());
}