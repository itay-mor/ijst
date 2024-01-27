//
// Created by Itay Mor on 19/12/2023.
//

#include <bits/stdc++.h>

using namespace std;

int min_price(vector<int> stairs) {
  stairs.push_back(0);
  auto n = stairs.size();

  vector<int> DP(n);
  DP[0] = stairs[0];
  DP[1] = stairs[1];
  DP[2] = stairs[2];
  for (int i = 3; i < n; ++i)
    DP[i] = stairs[i] + min({DP[i-1], DP[i-2], DP[i-3]});

  return DP[n-1];
}

int min_price_optimal(vector<int> stairs) {
  stairs.push_back(0);
  deque<int> available_stairs;
  for (int i = 0; i < 3; ++i) available_stairs.push_back(stairs[i]);

  for (int i = 3; i < stairs.size(); i++) {
    int new_stair = min({available_stairs[0], available_stairs[1], available_stairs[2]}) + stairs[i];
    available_stairs.pop_front();
    available_stairs.push_back(new_stair);
  }

  return available_stairs[2];
}

int main() {
  cout << min_price_optimal({10, 9, 8, 7, 6, 5, 4, 3, 2, 1});
}

