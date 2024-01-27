//
// Created by Itay Mor on 22/12/2023.
//

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int grid_path(vector<string> grid) {
  if (grid[0][0] == '*' || grid[grid.size() - 1][grid.size() - 1] == '*')
    return 0;

  vector<vector<int>> DP(grid.size(), vector<int>(grid.size()));
  DP[0][0] = 1;
  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid.size(); ++j) {
      if (i > 0 && grid[i - 1][j] != '*')
        DP[i][j] += DP[i - 1][j] % MOD;
      if (j > 0 && grid[i][j - 1] != '*')
        DP[i][j] += DP[i][j - 1] % MOD;
      DP[i][j] %= MOD;
    }

  }

  return DP[grid.size() - 1][grid.size() - 1];
}

int main() {
  int n; cin >> n;
  vector<string> grid(n);
  for (auto& row : grid)
    cin >> row;

  cout << grid_path(grid);
}