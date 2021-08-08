#pragma once
#include "AI.h"
#include <iostream>

class Easy : public Ai
{
private:
public:
    void make_move(Board &board) override;
};