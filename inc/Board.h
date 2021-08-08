#pragma once
#include <iostream>
#include <array>
#include <tuple>

using Input = std::tuple<size_t, size_t, char>;

class Board {
public:
    void drawBoard() const;
    void refresh(size_t row, size_t col, char mark);
    Input getUserInput();

private:
    
    std::array<std::array<char, 3>, 3> m_board = {{{'_', '_', '_'},
                                                   {'_', '_', '_'},
                                                   {'_', '_', '_'}}};
};
