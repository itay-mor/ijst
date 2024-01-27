//
// Created by Itay Mor on 25/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int connecting_numbers(const vector<int>& upper, const vector<int>& lower) {
  unordered_map<int, int> lower_locations;
  int n = upper.size();
  for (int i = 0; i < n; ++i) {
    lower_locations[lower[i]] = i;
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int x = n + 1;
      if (lower_locations.find(upper[i - 1]) != lower_locations.end())
        x = lower_locations[upper[i - 1]] + 1;

      if (x <= j)
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][x - 1] + 1);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  return dp[n][n];
}

int main() {
  cout << connecting_numbers(
      {1, 2, 3, 4, 5, 6},
      {3, 2, 1, 6, 5, 4}
  );
}