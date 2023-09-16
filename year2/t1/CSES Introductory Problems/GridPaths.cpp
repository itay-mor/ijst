//
// Created by Itay Mor on 15/09/2023.
//

#include <bits/stdc++.h>

constexpr int GRID_SIZE = 2;

using namespace std;

int64_t number_of_paths(string& path) {
  // Stop condition
  vector<tuple<int, int>> used_squares = {{0, 0}};
  tuple<int, int> start = {0, 0};

  int64_t solution = 0;
  int first_unknown = -1;
  for (int i = 0; i < path.length(); ++i) {
    if (path[i] == '?') {
      first_unknown = i;
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

    if (x >= GRID_SIZE || x < 0 || y >= GRID_SIZE || y < 0) {
      return 0;
    }
    for (auto used_square : used_squares) {
      if (used_square == start) return 0;
    }

    used_squares.push_back(start);
  }

  if (first_unknown == -1) return (start == make_tuple(0, GRID_SIZE - 1)) ? 1 : 0;

  path[first_unknown] = 'R';
  solution += number_of_paths(path);

  path[first_unknown] = 'L';
  solution += number_of_paths(path);

  path[first_unknown] = 'D';
  solution += number_of_paths(path);

  path[first_unknown] = 'U';
  solution += number_of_paths(path);

  path[first_unknown] = '?';

  return solution;
}

int64_t number_of_paths2(const string& path,
                         array<array<bool, GRID_SIZE>, GRID_SIZE> used_squares,
                         tuple<int, int> start_square = {0, 0},
                         const int& start_index = 0) {

  auto& [x, y] = start_square;
  if (x >= GRID_SIZE || x < 0 || y >= GRID_SIZE || y < 0) return 0;

  int64_t solution = 0;
  int first_unknown = -1;
  for (int i = start_index; i < path.length(); ++i) {
    if (path[i] == '?') {
      first_unknown = i;
      break;
    }
    switch (path[i]) {
      case 'R':start_square = {x + 1, y};
        break;
      case 'L':start_square = {x - 1, y};
        break;
      case 'U':start_square = {x, y - 1};
        break;
      case 'D':start_square = {x, y + 1};
        break;
    }

    if (x >= GRID_SIZE || x < 0 || y >= GRID_SIZE || y < 0) return 0;
    if (used_squares[y][x]) return 0;

    used_squares[y][x] = true;
  }

  if (first_unknown == -1) return (start_square == make_tuple(0, GRID_SIZE - 1)) ? 1 : 0;

  solution +=
      number_of_paths2(path, used_squares, {x + 1, y}, start_index + 1); // Right


  solution +=
      number_of_paths2(path, used_squares, {x - 1, y}); // Left

  solution +=
      number_of_paths2(path, used_squares, {x, y + 1}); // Down


  solution +=
      number_of_paths2(path, used_squares, {x, y - 1}); // Down




  return solution;
}

int main() {
  string path;
  cin >> path;

  cout << number_of_paths2(path, {});
}