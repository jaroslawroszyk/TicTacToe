#pragma once
#include "AI.h"
#include <iostream>

class Easy : public Ai
{
public:
    void make_move(Board &board) override;
};