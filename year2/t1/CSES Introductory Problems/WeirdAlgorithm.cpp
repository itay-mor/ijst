//
// Created by Itay Mor on 29/08/2023.
//
#include <iostream>
#include <cstdint>

using namespace std;

string run_weird_algorithm(int64_t n) {
    string s;

    while (n != 1) {
        s += (to_string(n) + " ");
        if (n % 2 == 0) { n /= 2; }
        else {
            n *=3;
            n++;
        }
    }
    s += '1';
    return s;
}

int main() {
    int64_t n; cin >> n;
    cout << run_weird_algorithm(n);
}