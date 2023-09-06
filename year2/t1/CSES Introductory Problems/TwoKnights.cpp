//
// Created by Itay Mor on 29/08/2023.
//
#include <iostream>
#include <cstdint>

int main() {
    int64_t x;
    std::cin >> x;
    for (int64_t n = 1; n <= x; n++) {
        std::cout << (n*n*n*n - 9*n*n + 24*n - 16)/2 << std::endl;
    }
}