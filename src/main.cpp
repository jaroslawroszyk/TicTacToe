#include "Board.h"
#include "TictactoeMode.h"
#include <iostream>
int main()
{
    Board board;
    menu();
    board.drawBoard();
    auto [row, col, mark]  = board.getUserInput();
    board.refresh(row, col, mark);
    board.drawBoard();
    
    return 0;
}
