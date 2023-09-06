#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by Itay Mor on 03/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

void move(int discs_number, int from, int to, int other) {
    if (discs_number == 1) {
        cout << from << " " << to << endl;
        return;
    }
    if (discs_number > 0) {
        move(discs_number - 1, from, other, to);
        move(1, from, to, other);
        move(discs_number - 1, other, to, from);
    }
}

int main() {
    int n;
    cin >> n;
    cout << pow(2,n) - 1 << endl;
    move(n, 1, 3, 2);
    return 0;
}
#pragma clang diagnostic pop