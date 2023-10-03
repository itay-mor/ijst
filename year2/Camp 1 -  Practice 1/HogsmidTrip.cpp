//
// Created by Itay Mor on 20/09/2023.
//

#include <iostream>
#include <vector>
#include <cstdint>
#define CHOOSE2(n) ((n*(n-1))/2)

using namespace std;

inline int positive_modulo(int64_t k, int n) {
  return (k % n + n) % n;
}

vector<int64_t> create_buckets(int64_t modulus, vector<int64_t> vec) {
  vector<int64_t> return_vec(modulus, 0);
  for (auto price : vec) {
    return_vec[price]++;
  }
  return return_vec;
}

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  int64_t input;
  for (size_t i = 0; i < size; i++) {
    cin >> input;
    return_vec[i] = input;
  }

  return return_vec;
}

void run_hogsmeade_trip() {
  int n; cin >> n;
  auto vec = read_vector(n);
  
  vector<int64_t> partial_sums_vector(n);
  partial_sums_vector[0] = positive_modulo(vec[0], n);
  for (size_t i = 1; i < n; i++) {
    partial_sums_vector[i] = positive_modulo(partial_sums_vector[i - 1] + vec[i], n);
  }

  int64_t solution = 0;
  auto buckets = create_buckets(n, partial_sums_vector);
  for (auto bucket : buckets) {
    solution += CHOOSE2(bucket);
  }

  solution += buckets[0];

  cout << solution;
}

int main() { run_hogsmeade_trip(); }
