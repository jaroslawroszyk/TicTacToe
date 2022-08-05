#pragma once

#include <map>
#include <random>

namespace board
{
    std::map<char , int> scores{{'_' , 0} ,
                                {'X' , -1} ,
                                {'O' , 1}};
} // boardScore

auto getRand(int min , int max)->size_t
{
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min , max);

    return static_cast<size_t>(distirb(gen));
}