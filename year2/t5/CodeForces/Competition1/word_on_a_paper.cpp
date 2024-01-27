//
// Created by Itay Mor on 26/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  vector<vector<char>> paper(8, vector<char>(8));
  int word_col, word_row;
  string word;
  bool found;
  while (t--) {
    word = "";
    found = false;
    for (int i = 0; i < 8; ++i) {
      for (int j = 0; j < 8; ++j) {
        cin >> paper[i][j];
        if (paper[i][j] != '.' && !found)
          word_col = j, word_row = i, found = true;
      }
    }
    while (word_row < 8 && paper[word_row][word_col] != '.') {
      word += paper[word_row][word_col];
      word_row++;
    }
    cout << word << '\n';
  }
}