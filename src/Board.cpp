#include "../include/Board.h"

#include <iostream>
#include <string>

auto Board::drawBoard() const -> void
{
    std::cout << "----1---2---3--\n";
    size_t row_cnt{1};
    for (const auto& row : m_board) {
        std::cout << row_cnt++ << " | ";
        for (const auto field : row) {
            std::cout << field << " | ";
        }
        std::cout << '\n';
    }
    std::cout << "---------------\n";
}

auto Board::refresh(size_t row, size_t col, char mark) -> void
{
    if (!isTaken(row, col)) {
        m_board[row - 1][col - 1] = mark;  // -1 cus of array indexing
        m_moves.push_back(std::make_pair(row, col));
    } else {
        std::cout << "You cannot move there\n";
    }
}

auto Board::getUserInput() -> Input
{
    size_t row, col;
    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Col: ";
    std::cin >> col;
    return {row, col};
}

auto Board::reset() -> void
{
    for (auto& row : m_board) {
        for (auto& field : row) {
            field = '_';
        }
    }
    m_moves.clear();
}

auto Board::isTaken(size_t x, size_t y) -> bool
{
    return std::find_if(m_moves.begin(), m_moves.end(), [=](const auto& move) {
               return (x == move.first && y == move.second);
           }) != m_moves.end();
}

auto Board::setField(size_t x , size_t y , char mark) -> void
{
    m_board[x][y] = mark;
}

auto Board::checkWinner() const -> char
{
    // Row
    for (size_t i = 0; i < 3; i++) {
        if (m_board[i][0] == m_board[i][1] && m_board[i][1] == m_board[i][2] && m_board[i][0] != '_') {
            return m_board[i][0];
        }
    }
    // Col
    for (size_t i = 0; i < 3; i++) {
        if (m_board[0][i] == m_board[1][i] && m_board[1][i] == m_board[2][i] && m_board[0][i] != '_') {
            return m_board[0][i];
        }
    }
    // Rdiag
    size_t i = 0;
    if (m_board[i][i] == m_board[i + 1][i + 1] && m_board[i + 1][i + 1] == m_board[i + 2][i + 2] && m_board[i][i] != '_') {
        return m_board[i][i];
    }

    // Ldiag
    if (m_board[i][i + 2] == m_board[i + 1][i + 1] && m_board[i + 1][i + 1] == m_board[i + 2][i] && m_board[i][i + 2] != '_') {
        return m_board[i][i + 2];
    }
    return '_';
}

auto Board::areMovesLeft() const -> bool
{
    for (const auto& row : m_board) {
        for (const auto field : row) {
            if (field == '_') {
                return true;
            }
        }
    }
    return false;
}

