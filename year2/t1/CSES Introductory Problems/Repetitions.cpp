//
// Created by Itay Mor on 29/08/2023.
//

#include <iostream>
#include <cstdint>

using namespace std;

int64_t run_repetitions(const string& s) {
    int64_t max_substring_length = 0;
    int64_t curr_substring_length = 1;
    char prev_char = ' ';
    for (char c : s) {
        if (c == prev_char) {
            curr_substring_length++;
        } else {
            curr_substring_length = 1;
        }
        max_substring_length = max(curr_substring_length, max_substring_length);
        prev_char = c;
    }

    return max_substring_length;
}

int main() {
    string s; cin >> s;
    cout << run_repetitions(s) << endl;
}