//
// Created by Itay Mor on 13/01/2024.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 1'000'000'007;

ll combinations(int n) {
  deque<ll> dp(6, 0);
  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 4;
  dp[3] = 8;
  dp[4] = 16;
  dp[5] = 32;
  if (n <= 6) return dp[n-1];
  for (int i = 7; i <= n; i++) {
    dp.push_back(0);
    dp[6] += dp[0]; dp[6] %= MOD;
    dp[6] += dp[1]; dp[6] %= MOD;
    dp[6] += dp[2]; dp[6] %= MOD;
    dp[6] += dp[3]; dp[6] %= MOD;
    dp[6] += dp[4]; dp[6] %= MOD;
    dp[6] += dp[5]; dp[6] %= MOD;
    dp.pop_front();
  }
  return dp[5];
}

int main() {
  int n; cin >> n;
  cout << combinations(n);
}