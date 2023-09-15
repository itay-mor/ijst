//
// Created by Itay on 08/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

constexpr int64_t MAX_VALUE = 1000000001;

using apple_pile = vector<int64_t>;

apple_pile read_apple_pile() {
  int n;
  cin >> n;

  apple_pile pile;
  pile.reserve(n);
  int64_t apple;
  for (int i = 0; i < n; ++i) {
    cin >> apple;
    pile.push_back(apple);
  }
  return pile;
}

int64_t run_apple_division(apple_pile& weights) {
  int64_t pile_sum = 0;
  for (auto apple : weights) {
    pile_sum += apple;
  }

  bitset<20> piles;
  int64_t min_diff = MAX_VALUE;
  for (int i = 0; i < (1 << (weights.size() - 1)); ++i) {
    int64_t curr_diff = 0;
    piles = bitset<20>(i);
    for (int j = 0; j < 20; ++j) {
      curr_diff += weights[j] * piles[j];
    }
    curr_diff = abs(pile_sum - 2 * curr_diff);
    min_diff = min(min_diff, curr_diff);
  }

  return min_diff;
}

int main() {
  auto pile = read_apple_pile();
  cout << run_apple_division(pile);
}
