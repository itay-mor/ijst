//
// Created by Itay Mor on 14/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (auto& coin : coins)
    cin >> coin;

  vector<int> dp(x + 1, -1);
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (auto coin : coins) {
      if (coin > i || dp[i-coin] == -1) continue;
      if (dp[i] == -1) dp[i] = dp[i-coin] + 1;
      else dp[i] = min(dp[i], dp[i-coin] + 1);
    }
  }

  cout << dp[x];
}