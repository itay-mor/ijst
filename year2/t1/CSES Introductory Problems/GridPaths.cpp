//
// Created by Itay Mor on 15/09/2023.
//

#include <bits/stdc++.h>

constexpr int GRID_SIZE = 7;

using namespace std;

int64_t number_of_paths(string& path) {
  // Stop condition
  vector<tuple<int, int>> used_squares = {{0, 0}};
  tuple<int, int> start = {0, 0};

  int64_t solutions = 0;
  int first_unknown_index = -1;
  for (int i = 0; i < path.length(); ++i) {
    if (path[i] == '?') {
      first_unknown_index = i;
      break;
    }
    auto& [x, y] = start;
    switch (path[i]) {
      case 'R':start = {x + 1, y};
        break;
      case 'L':start = {x - 1, y};
        break;
      case 'U':start = {x, y - 1};
        break;
      case 'D':start = {x, y + 1};
        break;
    }

    if (x < 0 || GRID_SIZE <= x ||
        y < 0 || GRID_SIZE <= y) {
      return 0;
    }
    for (const auto& used_square : used_squares) {
      if (used_square == start) return 0;
    }

    used_squares.push_back(start);
  }

  if (first_unknown_index == -1) return (start == make_tuple(0, GRID_SIZE - 1)) ? 1 : 0;

  path[first_unknown_index] = 'R';
  solutions += number_of_paths(path);

  path[first_unknown_index] = 'L';
  solutions += number_of_paths(path);

  path[first_unknown_index] = 'D';
  solutions += number_of_paths(path);

  path[first_unknown_index] = 'U';
  solutions += number_of_paths(path);

  path[first_unknown_index] = '?';

  return solutions;
}

int main() {
  string path;
  cin >> path;

  cout << number_of_paths(path);
}