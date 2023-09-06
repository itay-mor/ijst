//
// Created by Itay Mor on 30/08/2023.
//

#include <iostream>
#include <cstdint>
#include <cmath>

constexpr int64_t MODULUS (10*10*10*10*10*10*10*10*10 + 7);

int main() {
    int64_t n;
    std::cin >> n;

    int64_t power=1;
    for (int64_t i = 1; i <= n; ++i) {
        power *= 2;
        power %= MODULUS;
    }

    std::cout << power;
}