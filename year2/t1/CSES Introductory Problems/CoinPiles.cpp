//
// Created by Itay Mor on 31/08/2023.
//

#include <iostream>
#include <cstdint>

using namespace std;

string solve_coin_piles(int64_t a, int64_t b) {
    int64_t x = 2 * b - a, y=2 * a -b;
    if (x < 0 || y < 0) {
        return "NO";
    }
    return (!(x%3) && !(y%3)) ? "YES" : "NO";
}



int main() {
    int64_t n;
    cin >> n;
    string to_print;
    for (int i = 0; i < n; ++i) {
        int64_t a,b;
        cin >> a >> b;
        to_print += solve_coin_piles(a,b) + '\n';
    }

    cout << to_print;
}
