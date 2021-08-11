#pragma once
#include "AI.h"
#include <iostream>

class Medium : public Ai
{
private:
public:
    void make_move(Board &board) override;
};