//
// Created by Itay Mor on 02/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

void run_gray_code(int64_t n) {
    const uint64_t length = 1 << n;
    for (uint64_t i = 0; i < length; ++i) {
        string to_print;
        uint64_t gray_num = i ^ (i >> 1);
        to_print = bitset<16>(gray_num).to_string().substr(16-n, n);
        cout << to_print << endl;
    }
}

int main() {
    int64_t n;
    cin >> n;
    run_gray_code(n);
}