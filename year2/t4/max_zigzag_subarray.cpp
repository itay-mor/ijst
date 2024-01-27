//
// Created by Itay Mor on 24/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int max_zigzag_subarray(const vector<int>& numbers) {
  auto n = numbers.size();
  vector<int> ends_with_max(n + 1);
  vector<int> ends_with_min(n + 1);
  ends_with_max[0] = ends_with_min[0] = 1;

  for (int i = 1; i < n; ++i) {
    if (numbers[i - 1] >= numbers[i]) ends_with_max[i] = ends_with_max[i - 1];
    else ends_with_max[i] = max(ends_with_min[i - 1] + 1, ends_with_max[i - 1]);

    if (numbers[i - 1] <= numbers[i]) ends_with_min[i] = ends_with_min[i - 1];
    else ends_with_min[i] = max(ends_with_max[i - 1] + 1, ends_with_min[i - 1]);
  }
  return max(ends_with_max[n-1], ends_with_min[n-1]);
}

int main() {
  cout << max_zigzag_subarray({1, 2, 3, 2, 6, 5, 1, 2});
}
