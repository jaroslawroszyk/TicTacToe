#pragma once

#include "AI.h"
#include <iostream>

class Hard : public Ai
{
private:
    auto minimax(Board &board , bool isMax) -> int;

    auto findBestMove(Board &board) -> std::pair<size_t , size_t>;

public:
    auto make_move(Board &board) -> void override;

};
