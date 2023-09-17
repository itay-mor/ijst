//
// Created by Itay Mor on 15/09/2023.
//
#include <bits/stdc++.h>
#define CALC(counter)  (9*pow10(counter-1)*(counter))

using namespace std;

int64_t pow10(int64_t n) {
  int64_t result = 1;
  for (int64_t i = 0; i < n; ++i) result*=10;

  return result;
}

int64_t run_query(int64_t n) {
  int64_t chars_before_closest_k_digits_number = 0;
  int64_t counter = 1;

  int64_t i = 9, j = 0;
  while (i < n) {
    counter++;
    i += (int64_t) CALC(counter);
    j += (int64_t) CALC(counter-1);
    chars_before_closest_k_digits_number = j;
    cerr << i << " " << j << endl;

  }
  cerr << "counter: " << counter << endl;
  int64_t dist = n-chars_before_closest_k_digits_number;
  int64_t digit_type = pow10(1 + (counter - (dist%counter))%counter);
  cerr << "type: "<< digit_type << endl;

  int64_t digit = (pow10(counter-1) + ((dist-1)/counter));
  cerr << "digit: " << digit << endl;
  digit%=digit_type;
  digit -= digit%(digit_type/10);
  digit/= (digit_type/10);
  return digit;
}

void run_digit_queries(int64_t queries_number) {
  int64_t query;
  for (; queries_number > 0; queries_number--) {
    cin >> query;
    cout << run_query(query) << endl;
  }
}

int main() {
  int64_t q;
  cin >> q;

  run_digit_queries(q);
}