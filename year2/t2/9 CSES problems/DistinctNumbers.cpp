//
// Created by Itay Mor on 24/09/2023.
// https://cses.fi/problemset/task/1621
//

#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  int64_t temp;
  for (size_t i = 0; i < size; i++) {
    cin >> temp;
    return_vec[i] = temp;
  }

  return return_vec;
}

void run_distinct_numbers() {
  int64_t n;
  cin >> n;

  vector<bool> counting_vec(1000*1000*1000, false);
  int64_t distinct_numbers_count = 0;
  int64_t input_num;
  for (int64_t i = 0; i < n; ++i) {
    cin >> input_num;
    if (counting_vec[input_num]) continue;
    distinct_numbers_count++;
    counting_vec[input_num] = true;
  }

  cout << distinct_numbers_count;
}

int main() {
  run_distinct_numbers();
}