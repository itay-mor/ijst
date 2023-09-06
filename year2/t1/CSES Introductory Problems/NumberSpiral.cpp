//
// Created by Itay Mor on 29/08/2023.
//

#include <iostream>
#include <cstdint>

using namespace std;

int64_t solve_test(int64_t y, int64_t x) {
    int64_t y_header = ((y % 2 == 0) ? y*y : (y-1)*(y-1) + 1);
    int64_t x_header = ((x % 2 == 1) ? x*x : (x-1)*(x-1) + 1);

    if (y > x) {
        if (y%2 == 0) {
            return y_header - x + 1;
        }
        return y_header + x - 1;

    }

    if (x%2 == 0) {
        return x_header + y - 1;
    }
    return x_header - y + 1;
}

string run_number_spiral() {
    int64_t n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        int64_t y, x;
        cin >> y >> x;
        s += to_string(solve_test(y, x)) + '\n';
    }
    return s;
}

int main() {
    cout << run_number_spiral() << endl;
}