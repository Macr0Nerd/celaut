#ifndef CELAUT_CONWAY_HPP
#define CELAUT_CONWAY_HPP

#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0;0m"

#include "celaut/celaut.hpp"
#include <iostream>

namespace Conway {
    struct Cell {
        int alive = 0;
    };

    static void printBoard(const std::vector<std::vector<Cell>> &board) {
        for (auto &i : board) {
            for (auto &j : i) {
                if (j.alive) {
                    std::cout << CYAN << "█ " << RESET;
                } else {
                    std::cout << WHITE << "█ " << RESET;
                }
            }

            std::cout << std::endl;
        }
    }

    [[noreturn]] void play(std::vector<std::vector<Conway::Cell>> &board);
}

template<>
int CelAut<Conway::Cell>::update(std::vector<std::vector<Conway::Cell>> &board) {
    std::vector<std::vector<Conway::Cell>> copy = board;
    Conway::Cell* current;
    std::vector<Conway::Cell> around;
    int live;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            current = &board[i][j];
            around = CelAut::getAround(copy, i, j);
            live = 0;

            for (auto &k : around) {
                if (k.alive) {
                    ++live;
                }
            }

            if (current->alive && live < 2 || live > 3) {
                current->alive = 0;
            } else if (!current->alive && live == 3) {
                current->alive = 1;
            }
        }
    }

    return 0;
}

void Conway::play(std::vector<std::vector<Conway::Cell>> &board) {
    printBoard(board);

    while (true) {
        std::cin.ignore();

        CelAut<Cell>::update(board);
        printBoard(board);
    }
}

#endif //CELAUT_CONWAY_HPP
