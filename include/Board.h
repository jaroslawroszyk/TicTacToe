#pragma once

#include <array>
#include <iostream>
#include <tuple>
#include <vector>

using Input = std::tuple<size_t , size_t>;
using Array = std::array<std::array<char , 3> , 3>;
using Moves = std::vector<std::pair<size_t , size_t>>;

class Board
{
public:
    auto drawBoard() const -> void;

    auto refresh(size_t row , size_t col , char mark) -> void;

    auto getUserInput() ->Input;

    auto reset() -> void;

    auto isTaken(size_t x , size_t y) -> bool;

    auto checkWinner() const -> char;

    auto areMovesLeft() const -> bool;

    auto setField(size_t x , size_t y , char mark) -> void;

    auto getField(size_t x , size_t y) const -> char
    { return m_board[x][y]; }

    auto getBoard() const -> Array
    {
        return m_board;
    }

private:
    Moves m_moves{};
    Array m_board = {{{'_' , '_' , '_'} ,
                      {'_' , '_' , '_'} ,
                      {'_' , '_' , '_'}}};
};
