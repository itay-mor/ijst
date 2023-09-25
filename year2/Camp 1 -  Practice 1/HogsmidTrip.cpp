//
// Created by Itay Mor on 20/09/2023.
//

#include <iostream>
#include <vector>
#include <cstdint>
#define CHOOSE2(n) ((n*(n+1))/2)

using namespace std;

vector<int64_t> create_buckets(int64_t modulus, vector<int64_t> vec) {
  vector<int64_t> return_vec(modulus, 0);
  for (auto price : vec) {
    return_vec[price]++;
  }
  return return_vec;
}

// 1 2 5 6  7  29 -1
// 1 3 8 14 21 50 49

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  int64_t input;
  for (size_t i = 0; i < size; i++) {
    cin >> input;
    return_vec[i] = input;
  }

  return return_vec;
}

void run_hogsmead_trip_a() {
  int64_t n;
  cin >> n;
  auto vec = read_vector(n);
  vector<int64_t> partial_sums_vector(n);
  partial_sums_vector[0] = vec[0];
  for (size_t i = 1; i < n; i++) {
    partial_sums_vector[i] = partial_sums_vector[i-1] + vec[i];
  }

  int64_t solution = 0;
  for (int64_t i = 0; i < n - 1; i++) {
    for (size_t j = i; j < n; j++) {
      if ((partial_sums_vector[j] - ((i == 0) ? 0 :(partial_sums_vector[i-1]))) % n == 0) {
        solution++;
      }
    }
  }
  cout << solution;
}

void run_hogsmead_trip_b() {
  int64_t n;
  cin >> n;
  auto vec = read_vector(n);
  vector<int64_t> partial_sums_vector(n);
  partial_sums_vector[0] = vec[0];
  for (size_t i = 1; i < n; i++) {
    partial_sums_vector[i] = (partial_sums_vector[i-1] + vec[i]) % n;
    if (partial_sums_vector[i] % n < 0) {
      partial_sums_vector[i] += n;
    }
  }

  int64_t solution = 0;
  auto sorted_partial_sums = create_buckets(n, partial_sums_vector);
  for (auto element : sorted_partial_sums) {
    solution += CHOOSE2(element);
  }

  solution += sorted_partial_sums[0];

  cout << solution;
}


int main() {
  run_hogsmead_trip_b();
}

// 2 5 10 15 20