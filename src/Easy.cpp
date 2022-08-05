#include "../include/Easy.h"
#include "../helpers/HelpersToBoard.h"
#include <iostream>

auto Easy::make_move(Board &board)->void
{
    size_t x{} , y{};
    do
    {
        x = getRand(1 , 3);
        y = getRand(1 , 3);
    } while (board.isTaken(x , y));
    board.refresh(x , y , 'O');
}
