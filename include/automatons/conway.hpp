#ifndef CELAUT_CONWAY_HPP
#define CELAUT_CONWAY_HPP

#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0;0m"

#include "celaut/celaut.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <random>

namespace Conway {
    struct Cell {
        int alive = 0;

        /**
         * Operator overload for ==.
         * @param d The cell to be compared to.
         * @return Whether the cells were equal or not.
         */
        bool operator==(const Cell& d) const {
            return d.alive == alive;
        }
    };

    /**
     * Print's out the board to console.
     * @param board A 2-Dimensional vector containing the Cell struct.
     */
    static void printBoard(const std::vector<std::vector<Cell>> &board) {
        for (auto &i : board) {
            for (auto &j : i) {
                if (j.alive) {
                    std::cout << CYAN << "█" << RESET;
                } else {
                    std::cout << RESET << "█" << RESET;
                }
            }

            std::cout << std::endl;
        }
    }

    /**
     * Play Conway's Game of Life using a prebuilt board.
     * @param board A 2-Dimensional vector containing the Cell struct.
     */
    [[noreturn]] void play(std::vector<std::vector<Conway::Cell>> &board);

    /**
     * Play Conway's Game of Life with a fresh board with a randomized midsection.
     * @param x Height of the board (length of outer vector).
     * @param y Width of the board (length of inner vector).
     */
    [[noreturn]] void play(int x, int y);
}

/**
 * The specialized update function for Conway's Game of Life.
 * @param board A 2-Dimensional vector containing the Cell struct.
 * @return The success of updating the board. If it returns 1, the board is finished.
 */
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

    if (board==copy) {
        return 1;
    }

    return 0;
}

void Conway::play(std::vector<std::vector<Conway::Cell>> &board) {
    printBoard(board);

    while (true) {
        std::string response;
        getline(std::cin, response);

        if (response == "QUIT" || response == "STOP") {
            break;
        }

        if (CelAut<Cell>::update(board)) {
            break;
        }

        printBoard(board);
    }
}

void Conway::play(int x, int y) {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 1);

    std::vector<std::vector<Cell>> board;
    std::vector<Cell> sub;
    sub.assign(y, {0});
    board.assign(x, sub);

    for (int i = (x/4); i < x-(x/4); ++i) {
        for (int j = (y/4); j < y-(y/4); ++j) {
            board[i][j].alive = distribution(generator);
        }
    }
    printBoard(board);

    while (true) {
        std::string response;
        getline(std::cin, response);

        if (response == "QUIT" || response == "STOP") {
            break;
        }

        if (CelAut<Cell>::update(board)) {
            break;
        }

        printBoard(board);
    }
}

#endif //CELAUT_CONWAY_HPP
