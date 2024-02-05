//
// Created by Itay Mor on 05/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> children;
vector<int> dp;

int subtree_size(int node = 0) {
  if (children[node].empty()) return dp[node] = 1;
  int size = 1;
  for (auto child : children[node]) {
    if (dp[child] != -1)
      size += dp[child];
    else
      size += subtree_size(child);
  }

  return dp[node] = size;
}

int main() {
  int n; cin >> n;
  int x;
  children.resize(n);
  dp.resize(n, -1);
  for (int i = 1; i < n; ++i) {
    cin >> x;
    children[x - 1].push_back(i);
  }

  subtree_size();
  for (int i = 0; i < n; ++i) {
    cout << dp[i] - 1 << ' ';
  }
}