#pragma once
#include "AI.h"
#include <iostream>

class Medium : public Ai
{
private:
public:
    auto make_move(Board &board) -> void override;
};