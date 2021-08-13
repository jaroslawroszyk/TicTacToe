#include "Hard.h"

#include <algorithm>
#include <iostream>
#include <map>

std::map<char, int> scores{{'_', 0}, {'X', -1}, {'O', 1}};

int Hard::minimax(Board& board, bool isMax) {
    char res = board.checkWinner();
    if (!board.areMovesLeft()) {
        return scores[res];
    }
    if (isMax) {
        int bestScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getField(i, j) == '_') {
                    board.setField(i, j, 'O');
                    int score = minimax(board, !isMax);
                    board.setField(i, j, '_');
                    bestScore = std::max(score, bestScore);
                }
            }
        }
        return bestScore;
    } else {
        int worstScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board.getField(i, j) == '_') {
                    board.setField(i, j, 'X');
                    int score = minimax(board, !isMax);
                    board.setField(i, j, '_');
                    worstScore = std::min(score, worstScore);
                }
            }
        }
        return worstScore;
    }
}

std::pair<size_t, size_t> Hard::findBestMove(Board& board) {
    int x{-1}, y{-1};
    int bestScore = -1000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.getField(i, j) == '_') {
                board.setField(i, j, 'O');
                int score = minimax(board, false);
                board.setField(i, j, '_');
                if (score > bestScore) {
                    bestScore = score;
                    x = i;
                    y = j;
                }
            }
        }
    }
    return {x + 1, y + 1};
}

void Hard::make_move(Board& board) {
    auto move = findBestMove(board);
    board.refresh(move.first, move.second, 'O');
}
