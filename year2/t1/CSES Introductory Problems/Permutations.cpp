//
// Created by Itay Mor on 29/08/2023.
//
#define NO_SOLUTION "NO SOLUTION"


#include <iostream>

using namespace std;

string run_permutations(int64_t n) {
    if (2 <= n && n <= 3) {
        return NO_SOLUTION;
    }
    string odds;
    string evens;

    for (int64_t i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            odds += to_string(i) + " ";
        } else {
            evens += to_string(i) + " ";
        }
    }
    return evens + odds;

}

int main() {
    int64_t n; cin >> n;
    cout << run_permutations(n) << endl;
}