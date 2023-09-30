//
// Created by Itay Mor on 28/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  for (size_t i = 0; i < size; i++) cin >> return_vec[i];

  return return_vec;
}

void run_maximum_subarray_sum() {
  int64_t n;
  cin >> n;
  auto numbers = read_vector(n);

  int64_t temp_subarray_sum = 0, max_subarray_sum = numeric_limits<int64_t>::min();
  for (auto num : numbers) {
    temp_subarray_sum += num;
    max_subarray_sum = max(max_subarray_sum, temp_subarray_sum);
    if (temp_subarray_sum < 0) {
      temp_subarray_sum = 0;
    }

  }

  cout << max_subarray_sum;
}

int main() {
  run_maximum_subarray_sum();
}