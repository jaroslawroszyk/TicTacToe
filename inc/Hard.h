#pragma once
#include "AI.h"
#include <iostream>

class Hard : public Ai
{
private: 
    int minimax(Board& board, bool isMax);
    std::pair<size_t, size_t> findBestMove(Board& board);
    
public:
    void make_move(Board& board) override;
    
};
