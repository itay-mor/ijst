//
// Created by Itay Mor on 29/08/2023.
//
#include <iostream>
#include <cstdint>

using namespace std;

int64_t run_missing_number(int64_t n, int64_t sum) {
    return ((n*(n+1))/2) - sum;
}

int64_t read_sum(size_t size) {
    int64_t sum = 0;
    for (int i = 0; i < size; i++) {
        int64_t temp;
        cin >> temp;
        sum += temp;
    }
    return sum;
}

int main() {
    int64_t n; cin >> n;
    auto sum = read_sum(n-1);
    cout << run_missing_number(n, sum) << endl;

}