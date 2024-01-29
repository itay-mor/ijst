//
// Created by Itay Mor on 27/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

void test() {
  int n, q; cin >> n >> q;
  vector<int> candies(n);
  for (auto& candy : candies)
    cin >> candy;
  sort(candies.begin(), candies.end(), greater<>());
  vector<int> partial_sums(n + 1, 0);
  for (int i = 1; i <= n; ++i) partial_sums[i] = partial_sums[i-1] + candies[i - 1];


  int x;
  while (q--) {
    cin >> x;
    auto it = std::lower_bound(partial_sums.begin(), partial_sums.end(), x);
    if (it == partial_sums.end()) cout << -1 << '\n';
    else cout << it - partial_sums.begin() << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) {
    test();
  }
}