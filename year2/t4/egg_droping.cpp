//
// Created by Itay Mor on 25/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int min_drops(int n, int k) {
  int t;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1));

  for (int j = 0; j <= k; ++j) {
    dp[0][j] = 0;
    dp[1][j] = 1;
  }
  for (int i = 2; i <= n; ++i) {
    dp[i][1] = i;
  }

  for (int floors = 2; floors <= n; ++floors) {
    for (int eggs = 2; eggs <= k; ++eggs) {
      dp[floors][eggs] = numeric_limits<int>::max();
      for (int trys = 1; trys <= floors; ++trys) {
        t = max(dp[trys - 1][eggs - 1] + 1, dp[floors - trys][eggs] + 1);
        dp[floors][eggs] = min(t, dp[floors][eggs]);
      }
    }
  }
  return dp[n][k];
}

int main() {
  cout << min_drops(1000, 5);
}