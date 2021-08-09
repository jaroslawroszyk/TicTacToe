#include "Board.h"

#include <algorithm>
#include <iostream>
#include <string>

void Board::drawBoard() const {
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

void Board::refresh(size_t row, size_t col, char mark) {
    if (!isTaken(row, col)) {
        m_board[row - 1][col - 1] = mark;  // -1 cus of array indexing
        m_moves.push_back(std::make_pair(row, col));
    } else {
        std::cout << "You cannot move there\n";
    }
}

Input Board::getUserInput() {
    size_t row, col;
    std::cout << "Row: ";
    std::cin >> row;
    std::cout << "Col: ";
    std::cin >> col;
    return {row, col, 'X'};
}

void Board::reset() {
    for (auto& row : m_board) {
        for (auto& field : row) {
            field = '_';
        }
    }
}

bool Board::isTaken(size_t x, size_t y) {
    return std::find_if(m_moves.begin(), m_moves.end(), [=](const auto& move) {
               return (x == move.first && y == move.second);
           }) != m_moves.end();
}

char Board::checkWinner() const {
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
