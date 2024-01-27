//
// Created by Itay Mor on 23/12/2023.
//
#include <bits/stdc++.h>

using namespace std;



int64_t subarray_sums(const vector<int64_t>& numbers, int64_t value) {
  unordered_map<int64_t, int64_t> prev_sums;
  int64_t sum = 0, ans = 0;
  for (auto number : numbers) {
    sum += number;
    if (sum == value) ans++;
    if (prev_sums.find(sum - value) != prev_sums.end()) ans += prev_sums[sum - value];

    prev_sums[sum]++;
  }

  return ans;
}

int main() {
  int n, x;
  cin >> n >> x;
  vector<int64_t> numbers(n);
  for (auto& number : numbers)
    cin >> number;

  cout << subarray_sums(numbers, x);
}