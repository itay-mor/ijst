//
// Created by Itay Mor on 11/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

constexpr int CHESSBOARD_SIZE = 8;
constexpr int QUEENS_NUMBER = 8;

using QueensSet = set<tuple<int, int>>;
//using Chessboard = array<array<bool, 8>, 8>;
using Chessboard = array<string, CHESSBOARD_SIZE>;
//constexpr Chessboard chess_init = {
//    {true, true, true, true, true, true, true, true},
//    {true, true, true, true, true, true, true, true},
//    {true, true, true, true, true, true, true, true},
//    {true, true, true, true, true, true, true, true},
//    {true, true, true, true, true, true, true, true},
//    {true, true, true, true, true, true, true, true},
//    {true, true, true, true, true, true, true, true}
//    {true, true, true, true, true, true, true, true}
//};

Chessboard read_chessboard() {
  Chessboard chessboard{{}};
  for (int i = 0; i < CHESSBOARD_SIZE; ++i) {
    string row;
    cin >> row;

    chessboard[i] = row;
  }
  return chessboard;
}

Chessboard mark_attacked_squares(tuple<int, int> coordinates, Chessboard chessboard) {
  auto [x, y] = coordinates;
  for (int i = 0; i < CHESSBOARD_SIZE; ++i) {
    chessboard[i][x] = '*';
    if (x + i - y < CHESSBOARD_SIZE && x + i - y >= 0) chessboard[i][x + i - y] = '*';
    if (x - i + y < CHESSBOARD_SIZE && x - i + y >= 0) chessboard[i][x - i + y] = '*';
  }

  for (int i = 0; i < CHESSBOARD_SIZE; ++i) chessboard[y][i] = '*';

  return chessboard;
}

int64_t run_chessboards_and_queens(Chessboard chessboard, QueensSet& queens_set, vector<QueensSet>& queens_sets, int queens_num = QUEENS_NUMBER) {
  if (queens_num == 0) {
    queens_sets.push_back(queens_set);
    queens_set.clear();
    return 1;
  }

  int64_t total = 0;
  for (int i = 0; i < CHESSBOARD_SIZE; ++i) {
    for (int j = 0; j < CHESSBOARD_SIZE; ++j) {
      if (chessboard[i][j] == '*') continue;

      queens_set.emplace(make_tuple(j, i));
      if (find(queens_sets.begin(), queens_sets.end(), queens_set) != queens_sets.end()) continue;

      int64_t count = 1;
      Chessboard new_chessboard = mark_attacked_squares(make_tuple(j, i), chessboard);

      count *= run_chessboards_and_queens(new_chessboard, queens_set, queens_sets, queens_num - 1);
      total += count;
    }
  }

  return total;
}

int main() {
  Chessboard chessboard = read_chessboard();
  QueensSet queens_set = {};
  vector<QueensSet> queens_sets = {};
  cout << run_chessboards_and_queens(chessboard, queens_set, queens_sets);
}
