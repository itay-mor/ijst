//
// Created by Itay Mor on 29/08/2023.
//

#include <iostream>
#include <cstdint>

using namespace std;

int main() {
    int64_t n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO";
    } else {
        cout << "YES" << endl;
        string set1, set2;
        int64_t set1_counter = 0;
        int64_t set1_sum = 0;
        const int64_t half_sum = ((n + 1) * n) / 4;
        for (int64_t i = n; i > 0; i--) {
            if (i <= half_sum - set1_sum) {
                set1 += to_string(i) + " ";
                set1_sum += i;
                set1_counter++;
            } else {
                set2 += to_string(i) + " ";
            }
        }
        cout << set1_counter << endl << set1 << endl << n - set1_counter << endl << set2;
    }
}