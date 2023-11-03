//
// Created by Itay Mor on 07/10/2023.
//
#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>

constexpr uint64_t MODULUS = 1'000'000'007;

using namespace std;

uint64_t pow10(int n) {
  static uint64_t pow10[20] = {
      1,
      10,
      100,
      1'000,
      10'000,
      100'000,
      1'000'000,
      10'000'000,
      100'000'000,
      1'000'000'000,
      10'000'000'000,
      100000000000,
      1000000000000,
      10000000000000,
      100000000000000,
      1000000000000000,
      10000000000000000,
      100'000'000'000'000'000,
      1'000'000'000'000'000'000,
      10'000'000'000'000'000'000,
  };
  return pow10[n];
}

uint64_t part_of_num(int first_index, int last_index, uint64_t number) {
  uint64_t high_cast = pow10(first_index);
  uint64_t low_cast = pow10(last_index + 1);
//  cerr << first_index << " " << last_index << " " << ((number % low_cast) / high_cast) % MODULUS << "\n";
  return ((number % low_cast) / high_cast) % MODULUS;
}

int log10(uint64_t num) {
  int log = 0;
  while (num >= 10) {
    num /= 10;
    log += 1;
  }
  return log;
}

void run_arithmetic2() {
  uint64_t n;
  cin >> n;
  string number;
  for (uint64_t i = 0; i < n; i++) {
    cin >> number;
    auto number_length = number.length();
    uint64_t sum = 0;
    uint64_t last_sum_addition = 0;
    for (int j = 0; j < number_length; j++) {
      int digit = number[j] - '0';
      last_sum_addition = last_sum_addition*10 + (j+1)*digit;
      sum += last_sum_addition;
      sum %= MODULUS;
    }

    cout << sum << "\n";
  }
}

void run_arithmetic_game() {
  uint64_t n;
  cin >> n;
  uint64_t number;

  for (uint64_t i = 0; i < n; i++) {
    cin >> number;
    auto number_length = log10(number) + 1;
    uint64_t sum = 0;
    for (int j = 0; j < number_length; j++) {
      for (int k = 0; k < number_length - j; ++k) {
        sum += part_of_num(k, k + j, number);
        sum %= MODULUS;
      }
    }

    cout << sum << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  run_arithmetic2();
}