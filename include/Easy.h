#pragma once

#include "AI.h"
#include <iostream>

class Easy : public Ai
{
public:
    auto make_move(Board &board)->void override;
};