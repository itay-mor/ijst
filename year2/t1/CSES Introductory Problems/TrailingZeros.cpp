//
// Created by Itay Mor on 30/08/2023.
//

#include <iostream>
#include <cstdint>
#include <cmath>


int64_t run_trailing_zeros(int64_t n) {
    auto logarithm = static_cast<int64_t>(floor(log(n) / log(5)));
    auto closest_power = static_cast<int64_t>(pow(5, logarithm));
    int64_t trailing_zeros = 0;
    for (int64_t i = 5; i <= closest_power; i*=5) {
        trailing_zeros += n/i;
    }
    return trailing_zeros;
//    std::cout << static_cast<int64_t>(floor(n - n*(pow(5, -logarithm))))/4;

}

int main() {
    int64_t n;
    std::cin >> n;
    std::cout << run_trailing_zeros(n) << std::endl;

}
