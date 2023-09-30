//
// Created by Itay Mor on 29/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  for (size_t i = 0; i < size; ++i) cin >> return_vec[i];
  return return_vec;
}

void run_reading_books() {
  size_t n;
  cin >> n;

  auto books = read_vector(n);
  int64_t sum = accumulate(books.begin(), books.end(), (int64_t) 0);
  int64_t maximum = *max_element(books.begin(), books.end());

  cout << max(2 * maximum, sum);
}

int main() {
  run_reading_books();
}
