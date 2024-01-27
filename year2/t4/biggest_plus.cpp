//
// Created by Itay Mor on 24/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

pair<int, int> biggest_plus(const vector<vector<int>>& matrix) {
  int n = matrix.size();
  vector<vector<int>>
      up(n, vector<int>(n, 0)),
      down(n, vector<int>(n, 0)),
      left(n, vector<int>(n, 0)),
      right(n, vector<int>(n, 0));

  for (int i = 0; i < n; ++i) {
    for (int j = n - 2; j > 0; --j) {
      if (matrix[i][j] == 0 || matrix[i][j - 1] == 0) continue;
      right[i][j] = right[i][j + 1] + 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      if (matrix[i][j] == 0 || matrix[i][j - 1] == 0) continue;
      left[i][j] = left[i][j - 1] + 1;
    }
  }

  for (int j = 0; j < n; ++j) {
    for (int i = 1; i < n; ++i) {
      if (matrix[i][j] == 0 || matrix[i - 1][j] == 0) continue;
      up[i][j] = up[i - 1][j] + 1;
    }
  }

  for (int j = 0; j < n; ++j) {
    for (int i = n - 2; i > 0; --i) {
      if (matrix[i][j] == 0 || matrix[i + 1][j] == 0) continue;
      down[i][j] = down[i + 1][j] + 1;
    }
  }

  int biggest_plus_size = 0, curr_plus_size;
  pair<int, int> biggest_plus_coords = {-1, -1};

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] == 0) continue;
      curr_plus_size = min({right[i][j], left[i][j], down[i][j], up[i][j]});
      if (curr_plus_size > biggest_plus_size) {
        biggest_plus_size = curr_plus_size;
        biggest_plus_coords = {j, i};
      }
    }
  }

  return biggest_plus_coords;
}

int main() {
  auto ans = biggest_plus(
      {
          {0, 1, 0, 1, 0},
          {1, 0, 1, 1, 1},
          {0, 1, 0, 1, 0},
          {0, 0, 0, 0, 0},
          {0, 0, 0, 0, 0},
      }
  );

  cout << ans.first << " " << ans.second;
}