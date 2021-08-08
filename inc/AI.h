#pragma once
#include <iostream>
#include "Board.h"

class Ai
{
public:
    virtual void make_move(Board &board) = 0;
};