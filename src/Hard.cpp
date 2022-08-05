#include "../include/Hard.h"
#include "../helpers/HelpersToBoard.h"
#include <iostream>

auto Hard::minimax(Board &board , bool isMax)->int
{
    char res = board.checkWinner();
    if (!board.areMovesLeft())
    {
        return board::scores[res];
    }
    if (isMax)
    {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board.getField(i , j) == '_')
                {
                    board.setField(i , j , 'O');
                    int score = minimax(board , !isMax);
                    board.setField(i , j , '_');
                    bestScore = std::max(score , bestScore);
                }
            }
        }
        return bestScore;
    } else
    {
        int worstScore = 1000;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board.getField(i , j) == '_')
                {
                    board.setField(i , j , 'X');
                    int score = minimax(board , !isMax);
                    board.setField(i , j , '_');
                    worstScore = std::min(score , worstScore);
                }
            }
        }
        return worstScore;
    }
}

auto Hard::findBestMove(Board &board)->std::pair<size_t , size_t>
{
    int x{-1} , y{-1};
    int bestScore = -1000;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board.getField(i , j) == '_')
            {
                board.setField(i , j , 'O');
                int score = minimax(board , false);
                board.setField(i , j , '_');
                if (score > bestScore)
                {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return {x + 1 , y + 1};
}

auto Hard::make_move(Board &board)->void
{
    auto move = findBestMove(board);
    board.refresh(move.first , move.second , 'O');
}
