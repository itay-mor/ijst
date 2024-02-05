//
// Created by Itay Mor on 05/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> h(n), s(n);
  for (int i = 0; i < n; ++i)
    cin >> h[i] >> s[i];

  vector<vector<int>> dp(n, vector<int>(x));
  // dp[i][j] = max(dp[i-1][j], dp[i-1][j-s[i]] + h[i]

}