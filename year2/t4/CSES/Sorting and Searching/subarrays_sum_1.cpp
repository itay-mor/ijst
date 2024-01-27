//
// Created by Itay Mor on 22/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int subarray_sums_1(const vector<int64_t>& numbers, int64_t x) {
  if (numbers.size() == 1)
    return numbers[0] == x;

  vector<int> partial_sums(numbers.size() + 1);
  partial_sums[0] = 0;
  for (int i = 1; i <= numbers.size(); ++i)
    partial_sums[i] = partial_sums[i-1] + numbers[i-1];

  int left_p = 0, right_p = 1, ans = 0;
  while (right_p <= numbers.size()) {
    ans += partial_sums[right_p] - partial_sums[left_p] == x;

    if (partial_sums[right_p] - partial_sums[left_p] <= x)
      right_p++;
    else
      left_p++;

  }

  return ans;
}

int main() {
  int n, x; cin >> n >> x;
  vector<int64_t> numbers(n);
  for (auto& number : numbers) cin >> number;

  cout << subarray_sums_1(numbers, x);
}