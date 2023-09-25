//
// Created by Itay Mor on 15/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

int64_t pow10(int64_t n) {
  int64_t result = 1;
  for (int64_t i = 0; i < n; ++i) result *= 10;

  return result;
}

int64_t length_of_k_digit_numbers(int64_t k) {
  return 9 * pow10(k - 1) * (k);
}

int64_t get_number_digit(int64_t number, int64_t place_from_right, int64_t digits_in_number) {
  int64_t number_of_shifts = place_from_right - 1;
  for (int64_t i = 0; i < number_of_shifts; i++) {
    number /= 10;
  }
  int64_t digit = number % 10;
  return digit;
}

int64_t run_query(int64_t digit_index) {
  int64_t chars_before_closest_k_digits_number = 0;
  int64_t digits_in_number = 1;

  // Calculate chars_before_closest_k_digits_number.
  int64_t i = 9;
  while (i < digit_index) {
    digits_in_number++;
    i += length_of_k_digit_numbers(digits_in_number);
    chars_before_closest_k_digits_number += length_of_k_digit_numbers(digits_in_number - 1);
  }
  int64_t index_of_first_k_digit_num = chars_before_closest_k_digits_number + 1;
  // Zero-based distance.
  int64_t dist = digit_index - index_of_first_k_digit_num;
  int64_t place_from_left = dist % digits_in_number; // 0-based.
  int64_t place_from_right = digits_in_number - place_from_left; // 1-based.

  int64_t number = pow10(digits_in_number - 1) + (dist / digits_in_number);
  int64_t digit = get_number_digit(number, place_from_right, digits_in_number);

  return digit;
}

void run_digit_queries(int64_t number_of_queries) {
  int64_t digit_index;
  for (; number_of_queries > 0; number_of_queries--) {
    cin >> digit_index;
    cout << run_query(digit_index) << endl;
  }
}

int main() {
  int64_t number_of_queries;
  cin >> number_of_queries;

  run_digit_queries(number_of_queries);
}