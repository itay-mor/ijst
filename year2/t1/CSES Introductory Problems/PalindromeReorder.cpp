//
// Created by Itay Mor on 01/09/2023.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define NO_SOLUTION "NO SOLUTION"

using namespace std;

string run_palindrome_reorder(const string& s) {
    string odd;
    string return_value;
    vector<int64_t> char_counter(26);
    for (char c : s) {
        char_counter[c - 'A']++;
    }
    for (int64_t i = 0; i < 26; i++) {
        auto element = char_counter[i];
        if (element == 0) {
            continue;
        }
        if (element % 2 != 0) {
            if (!odd.empty()) {return NO_SOLUTION;}
            odd += (char) (i + 'A');
        }
        for (int64_t j = 0; j < element / 2; j++) {
            return_value += (char) (i + 'A');
        }
    }

    string return_value_end = return_value;
    reverse(return_value_end.begin(), return_value_end.end());
    return_value += odd + return_value_end;
    return return_value;
}


int main() {
    string s;
    cin >> s;
    cout << run_palindrome_reorder(s);
}