//
// Created by Itay Mor on 23/12/2023.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> visited;
vector<string> grid;
int n, m, rooms = 0;

inline bool is_floor(int x, int y) {
  return (x >= 0) && (y >= 0) && (x < n) && (y < m) && grid[x][y] == '.';
}

void mark_room(int x, int y) {
  visited[x][y] = true;
  if (is_floor(x + 1, y) && !visited[x + 1][y]) mark_room(x + 1, y);
  if (is_floor(x, y + 1) && !visited[x][y + 1]) mark_room(x, y + 1);
  if (is_floor(x - 1, y) && !visited[x - 1][y]) mark_room(x - 1, y);
  if (is_floor(x, y - 1) && !visited[x][y - 1]) mark_room(x, y - 1);
}

int count_rooms() {
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (is_floor(i, j) && !visited[i][j]) {
        mark_room(i, j);
        rooms++;
      }

  return rooms;
}

int main() {
  cin >> n >> m;
  grid = vector<string>(n);
  visited = vector<vector<bool>>(n, vector<bool>(m, false));

  for (auto& row : grid)
    cin >> row;

  cout << count_rooms();

}