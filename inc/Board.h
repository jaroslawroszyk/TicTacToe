#pragma once
#include <array>
#include <iostream>
#include <tuple>
#include <vector>

using Input = std::tuple<size_t, size_t>;
using Array = std::array<std::array<char, 3>, 3>;
using Moves = std::vector<std::pair<size_t, size_t>>;

class Board {
public:
    void drawBoard() const;
    void refresh(size_t row, size_t col, char mark);
    Input getUserInput();
    void reset();
    bool isTaken(size_t x, size_t y);
    char checkWinner() const;

    Array getBoard() const {
        return m_board;
    }

private:
    Moves m_moves{};
    Array m_board = {{{'_', '_', '_'},
                      {'_', '_', '_'},
                      {'_', '_', '_'}}};
};
