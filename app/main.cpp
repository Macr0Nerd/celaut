#include "automatons/conway.hpp"

int main() {
    std::vector<std::vector<Conway::Cell>> board;
    std::vector<Conway::Cell> sub;
    sub.assign(50, {0});
    board.assign(20, sub);

    for (int i = 6; i < 14; ++i) {
        for (int j = 20; j < 35; ++j) {
            board[i][j].alive = rand() % 2;
        }
    }

    Conway::play(board);
    return 0;
}
