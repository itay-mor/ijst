//
// Created by Itay Mor on 14/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& tiles, int n) {
  int m = tiles.size();
  vector<vector<int>> dp(n, vector<int>(m)); // dp[i][k] is the number of ways to tile a row in length i with
                                                      // the last tile being tiles[k];

  for (int i = 0; i < m; ++i)
    dp[0][i] = 0;


  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < m; ++k) {

    }
  }
}
int main() {
}