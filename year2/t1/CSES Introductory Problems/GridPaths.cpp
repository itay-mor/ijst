//
// Created by Itay Mor on 15/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

constexpr int GRID_SIZE = 7;
string path;

bool illegal_path_hit(const array<array<bool, GRID_SIZE + 2>, GRID_SIZE + 2>& grid,
    const int x, const int y) {
  if (grid[y][x + 1] && grid[y][x - 1] &&
      !grid[y + 1][x] && !grid[y - 1][x]) {
    return true;
  }

  if (grid[y + 1][x] && grid[y - 1][x] &&
      !grid[y][x + 1] && !grid[y][x - 1]) {
    return true;
  }

  return false;
}

int number_of_paths(
    array<array<bool, GRID_SIZE + 2>, GRID_SIZE + 2>& grid,
    int x = 1, int y = 1,
    unsigned int index = 0) {
  // Stop conditions:
  // Already used square.
  if (grid[y][x])
    return 0;

  if (index == path.length() && x == 1 && y == GRID_SIZE) {
    return 1;
  }

  if (index == path.length() || (x == 1 && y == GRID_SIZE)) {
    return 0;
  }

  if (illegal_path_hit(grid, x, y)) {
    return 0;
  }

  grid[y][x] = true;
  const char curr_direction = path[index];
  index++;
  int solutions;
  switch (curr_direction) {
    case 'R':
      solutions = number_of_paths(grid, x + 1, y, index);
      break;
    case 'L':
      solutions = number_of_paths(grid, x - 1, y, index);
      break;
    case 'D':
      solutions = number_of_paths(grid, x, y + 1, index);
      break;
    case 'U':
      solutions = number_of_paths(grid, x, y - 1, index);
      break;
    case '?':
      solutions = number_of_paths(grid, x + 1, y, index) // Right
          + number_of_paths(grid, x - 1, y, index) // Left
          + number_of_paths(grid, x, y + 1, index) // Down
          + number_of_paths(grid, x, y - 1, index); // Up
      break;
    default:
      cerr << "Unknown direction (" << curr_direction << ")" << endl;
      return 0;
  }
  grid[y][x] = false;
  return solutions;
}

int main() {
  cin >> path;

  array<array<bool, GRID_SIZE + 2>, GRID_SIZE + 2> grid = {};
  for (int i = 0; i < GRID_SIZE + 1; i++) {
    grid[0][i] = true;
    grid[GRID_SIZE + 1][i] = true;
    grid[i][0] = true;
    grid[i][GRID_SIZE + 1] = true;
  }

  cout << number_of_paths(grid) << endl;
}