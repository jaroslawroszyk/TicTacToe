#pragma once
#include <iostream>
#include "Board.h"

class Ai
{
private:
    int order{};
public:
    virtual void make_move(Board &board) = 0;
};