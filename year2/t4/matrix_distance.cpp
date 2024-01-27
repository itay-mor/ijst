//
// Created by Itay Mor on 22/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

template<typename T>
using matrix = vector<vector<T>>;

matrix<int> layers, A;
int n, m;

bool is_legal(pair<int, int> coord) {
  return coord.first >= 0 && coord.second >= 0 && coord.first < m && coord.second < n;
}

void bfs() {
  queue<pair<int, int>> bfs;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (A[i][j] == 0) {
        bfs.emplace(j, i);
        layers[i][j] = 0;
      }

  pair<int, int> curr;
  pair<int, int> neighbor;
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  while (!bfs.empty()) {
    curr = bfs.front();
    bfs.pop();
    for (auto direction : directions) {
      neighbor = {curr.first + direction.first, curr.second+direction.second};
      if (!is_legal(neighbor)) continue;
      if (layers[neighbor.second][neighbor.first] != -1) continue;
      layers[neighbor.second][neighbor.first] = layers[curr.second][curr.first] + 1;
      bfs.push(neighbor);
    }
  }
}

int main() {
  cin >> n >> m;
  A = matrix<int>(n, vector<int>(m));
  layers = matrix<int>(n, vector<int>(m, -1));

  for (auto& row : A)
    for (auto& col : row)
      cin >> col;


  bfs();

  for (auto& row : layers) {
    for (auto col : row) cout << col << " ";
    cout << endl;
  }


  return 0;
}