#ifndef CELAUT_ENTERPRISE_HPP
#define CELAUT_ENTERPRISE_HPP

#include "celaut/celaut.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <random>
#include <cmath>

namespace Enterprise {
    float fourPrecision(float);

    struct Cell {
        unsigned char type = 32; /// 32 for space, 35 for rooms, 37 for airlock, 45 for horizontal hallway, 124 for vertical hallway
        float integrity = 0.0;
        char direction = 0; /// 1 up,  right, 3 down, 4 left, 5 vertical, 6 horizontal
        bool set = false;

        /**
         * Operator overload for ==.
         * @param d The cell to be compared to.
         * @return Whether the cells were equal or not.
         */
        bool operator==(const Cell &d) const {
            return (d.type == type) && (fourPrecision(d.integrity) == fourPrecision(integrity)) &&
                   (d.direction == direction) && (d.set && set);
        }
    };

    /**
     * A function to set float precision to 4.
     * @param x The float to set the precision to.
     * @return The supplied float in four precision.
     */
    float fourPrecision(const float x) {
        const float value = 0.0001;
        return (int) (x / value) * value;
    }

    /**
     * Prints out the board to the console.
     * @param board A 2-dimensional vector containing the Cell struct
     */
    static void printBoard(const std::vector<std::vector<Cell>> &board) {
        for (auto &i : board) {
            for (auto &j : i) {
                std::cout << j.type << std::flush;
            }

            std::cout << std::endl;
        }
    }
}

/**
 * The specialized update function for Rule 1701.
 * @param board A 2-Dimensional vector constaining the Cell Struct.
 * @return The success of updating the board. If it returns 1, the board has finished updating.
 */
template<>
int CelAut<Enterprise::Cell>::update(std::vector<std::vector<Enterprise::Cell>> &board) {
    std::vector<std::vector<Enterprise::Cell>> copy = board;
    Enterprise::Cell *current;
    std::vector<Enterprise::Cell> around;
    float tegridy;
    static float track = 0;

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            current = &copy[i][j];

            if (!current->set && current->type != 32) {
                tegridy = current->integrity;
                board[i][j].set = true;

                switch (current->type) {
                    case 35: {
                        if (tegridy > 0.3000f) {
                            int dir = 0, xadj = 0, yadj = 0;

                            auto getAdj = [&](int off) {
                                dir = (current->direction + off) % 4;
                                dir = dir ? dir : 4;
                                xadj = (dir % 2) ? (dir == 1 ? -1 : 1) : 0;
                                yadj = (dir % 2) ? 0 : dir == 2 ? 1 : -1;
                            };

                            if (tegridy <= 0.4000f) {
                                getAdj(-1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            } else if (tegridy <= 0.4500f) {
                                getAdj(1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            } else if (tegridy <= 0.5000f) {
                                getAdj(0);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            } else if (tegridy <= 0.6000f) {
                                getAdj(-1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }

                                getAdj(1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            } else if (tegridy <= 0.7000f) {
                                getAdj(0);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }

                                getAdj(1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            } else if (tegridy <= 0.8000f) {
                                getAdj(0);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }

                                getAdj(-1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            } else if (tegridy <= 1.0000f) {
                                getAdj(0);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }

                                getAdj(1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }

                                getAdj(-1);
                                if ((i + xadj) != 0 && (i + xadj) != board.size() && (j + yadj) != 0 &&
                                    (j + yadj) != board[i].size() & board[i + xadj][j + yadj].type == 32) {
                                    board[i + xadj][j + yadj] = {35, tegridy * 0.9f, (char) dir};
                                }
                            }
                        }

                        break;
                    }
                    case 37: {
                        if (tegridy <= 0.1250f) {
                            if (i != 0 && board[i - 1][j].type == 32) {
                                board[i - 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 1};
                            }
                        } else if (tegridy <= 0.2500f) {
                            if (j != board[i].size() - 1 && board[i][j + 1].type == 32) {
                                board[i][j + 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 2};
                            }
                        } else if (tegridy <= 0.3750f) {
                            if (i != board.size() - 1 && board[i + 1][j].type == 32) {
                                board[i + 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 3};
                            }
                        } else if (tegridy <= 0.5000f && board[i][j - 1].type == 32) {
                            if (j != 0) {
                                board[i][j - 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 4};
                            }
                        } else if (tegridy <= 0.6250f) {
                            if (i != 0 && i != board.size() - 1 && board[i - 1][j].type == 32 &&
                                board[i + 1][j].type == 32) {
                                board[i - 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 1};
                                board[i + 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 3};
                            }
                        } else if (tegridy <= 0.7500f) {
                            if (j != board[i].size() - 1 && j != 0 && board[i][j + 1].type == 32 &&
                                board[i][j - 1].type == 32) {
                                board[i][j + 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 2};
                                board[i][j - 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 4};
                            }
                        } else if (tegridy <= 0.8125f) {
                            if (i != 0 && j != board[i].size() - 1 && board[i - 1][j].type == 32 &&
                                board[i][j + 1].type == 32) {
                                board[i - 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 1};
                                board[i][j + 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 2};
                            }
                        } else if (tegridy <= 0.8750f) {
                            if (j != board[i].size() - 1 && i != board.size() - 1 && board[i + 1][j].type == 32 &&
                                board[i][j + 1].type == 32) {
                                board[i][j + 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 2};
                                board[i + 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 3};
                            }
                        } else if (tegridy <= 0.9375f) {
                            if (i != board.size() - 1 && j != 0 && board[i + 1][j].type == 32 &&
                                board[i][j - 1].type == 32) {
                                board[i + 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 3};
                                board[i][j - 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 4};
                            }
                        } else if (tegridy <= 1.0000f) {
                            if (i != 0 && j != 0 && board[i - 1][j].type == 32 && board[i][j - 1].type == 32) {
                                board[i - 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f), 1};
                                board[i][j - 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f), 4};
                            }
                        }

                        break;
                    }
                    case 45:
                    case 124: {
                        int bend = 0;
                        int adj = 0;
                        float nt = Enterprise::fourPrecision(tegridy * 0.9f);
                        char dir = current->direction;

                        if (tegridy <= 0.4000f) {
                            bend = ((int) std::floor(tegridy * 100));

                            bend = !(bend % 2) ? 2 : (bend % 4);

                            nt += 0.6000f;
                        }

                        switch (current->direction) {
                            case 1: {
                                if (i != 0) {
                                    if (current->direction == 1) {
                                        adj = -1;
                                    }
                                } else {
                                    continue;
                                }
                            }
                            case 3: {
                                if (i != board.size() - 1) {
                                    if (current->direction == 3) {
                                        adj = 1;
                                    }
                                } else {
                                    continue;
                                }

                                switch (bend) {
                                    case 2: {
                                        dir = 6;
                                        break;
                                    }
                                    case 3: {
                                        --dir;
                                        dir = dir ? dir : 4;
                                        break;
                                    }
                                    case 1: {
                                        ++dir;
                                        break;
                                    }
                                }

                                if (board[i + adj][j].type == 32) {
                                    board[i + adj][j] = {static_cast<unsigned char>(bend ? 45 : 124), nt, dir};
                                }

                                break;
                            }
                            case 2: {
                                if (j != board[i].size() - 1) {
                                    if (current->direction == 2) {
                                        adj = 1;
                                    }
                                } else {
                                    continue;
                                }
                            }
                            case 4: {
                                if (j != 0) {
                                    if (current->direction == 4) {
                                        adj = -1;
                                    }
                                } else {
                                    continue;
                                }

                                switch (bend) {
                                    case 2: {
                                        dir = 5;
                                        break;
                                    }
                                    case 3: {
                                        --dir;
                                        break;
                                    }
                                    case 1: {
                                        ++dir;
                                        dir %= 4;
                                        dir = dir ? dir : 4;
                                        break;
                                    }
                                }

                                if (board[i][j + adj].type == 32) {
                                    board[i][j + adj] = {static_cast<unsigned char>(bend ? 124 : 45), nt, dir};
                                }

                                break;
                            }
                            case 5: {
                                if (i != 0 && board[i - 1][j].type == 32) {
                                    board[i - 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f + 0.6f), 1};
                                }

                                if (i != board.size() - 1 && board[i + 1][j].type == 32) {
                                    board[i + 1][j] = {124, Enterprise::fourPrecision(tegridy * 0.9f + 0.6f), 3};
                                }

                                break;
                            }
                            case 6: {
                                if (j != 0 && board[i][j - 1].type == 32) {
                                    board[i][j - 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f + 0.6f), 4};
                                }

                                if (j != board[i].size() - 1 && board[i][j + 1].type == 32) {
                                    board[i][j + 1] = {45, Enterprise::fourPrecision(tegridy * 0.9f + 0.6f), 2};
                                }

                                break;
                            }
                        }

                        int ro1 = ((int) std::floor(tegridy * 100)) % 3, ro2 = ((int) std::floor(tegridy * 10)) % 2;

                        if (tegridy >= 0.4500f && tegridy <= 0.8500f && !ro1) {
                            adj = ro2 ? 1 : -1;

                            dir += adj;

                            dir = dir ? dir : 4;

                            if (current->type == 45 && board[i + adj][j].type == 32) {
                                board[i + adj][j] = {35, Enterprise::fourPrecision(tegridy * 0.9f), dir};
                            } else if (current->type == 124 && board[i][j + adj].type == 32) {
                                board[i][j + adj] = {35, Enterprise::fourPrecision(tegridy * 0.9f), dir};
                            }
                        }

                        break;
                    }
                    default: {
                        continue;
                    }
                }
            } else {
                current->set = false;

                continue;
            }
        }
    }

    if (track == tegridy) {
        return 1;
    }

    track = tegridy;

    return 0;
}

#endif //CELAUT_ENTERPRISE_HPP
