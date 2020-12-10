#pragma once

#ifndef CELAUT_HPP
#define CELAUT_HPP

#include <vector>
#include <string>

template<class CellProperties>
class CelAut {
public:
    static int update(std::vector<std::vector<CellProperties>> &board);

    static std::vector<CellProperties> getAround(const std::vector<std::vector<CellProperties>> &board, int x, int y) {
        std::vector<CellProperties> list, tmp;

        if (x < 0 || y < 0) {
            return list;
        }

        for (int i = -1; i < 2; ++i) {
            if (x+i >= 0 && x+i < board.size()) {
                tmp = board[x+i];

                for (int j = -1; j < 2; ++j) {
                    if (y+j >= 0 && y+j < tmp.size()) {
                        if (i == 0 && j == 0) {
                            continue;
                        }

                        list.push_back(tmp[y+j]);
                    }
                }
            }
        }

        return list;
    }
};

#endif //CELAUT_HPP
