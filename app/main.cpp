#include "automatons/enterprise.hpp"

int main() {
    std::vector<std::vector<Enterprise::Cell>> x = {{}};
    x[0].assign(50, {});
    x.assign(50, x[0]);

    x[28][20] = {37, 0.3792f};
    x[13][28] = {37, 0.8073f};
    x[43][14] = {37, 0.3956f};
    x[37][42] = {37, 0.1974f};
    x[45][12] = {37, 0.3856f};
    x[7][39] = {37, 0.2845f};
    x[47][4] = {37, 0.6294f};

    int cnt = 0;

    while(!CelAut<Enterprise::Cell>::update(x)){
        ++cnt;
    }

    std::cout << cnt << std::endl;
    printBoard(x);

    return 0;
}
