#include "Easy.h"

#include <iostream>
#include <random>

size_t getRand(int min, int max) {
    std::random_device device;
    std::mt19937 gen(device());
    std::uniform_int_distribution<int> distirb(min, max);

    return static_cast<size_t>(distirb(gen));
}

void Easy::make_move(Board& board) {
    size_t x{}, y{};
    do {
        x = getRand(1, 3);
        y = getRand(1, 3);
    } while (board.isTaken(x, y));
    board.refresh(x, y, 'O');
}
