//
// Created by Itay Mor on 22/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int removing_digits(int n) {
  vector<int> DP(n+1);
  DP[0] = 0;
  for (int i = 1; i <= n; ++i) {
    DP[i] = i;
    int temp = i;
    while (temp > 0) {
      DP[i] = min(DP[i], DP[i - temp%10] + 1);
      temp /= 10;
    }
  }

  return DP[n];
}

int main() {
  int n;
  cin >> n;
  cout << removing_digits(n);
}