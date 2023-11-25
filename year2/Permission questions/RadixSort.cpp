//
// Created by Itay Mor on 10/11/2023.
//
constexpr int BASE = 2;

#include <bits/stdc++.h>

using namespace std;

inline int powBASE(int n) {
  static int powers[] = {
      1, BASE, BASE*BASE, BASE*BASE*BASE, BASE*BASE*BASE*BASE, BASE*BASE*BASE*BASE*BASE,
      BASE*BASE*BASE*BASE*BASE*BASE, BASE*BASE*BASE*BASE*BASE*BASE*BASE, BASE*BASE*BASE*BASE*BASE*BASE*BASE*BASE, BASE*BASE*BASE*BASE*BASE*BASE*BASE*BASE,
  };
  return powers[n];
}

void in_place_radix_sort(vector<int>& numbers, int max_length) {

  for (int i = 0; i < powBASE(max_length); i *= BASE) {
    vector<vector<int>> buckets(BASE);
    for (int number : numbers) {
      auto b = (number % powBASE(i + 1)) - (number % powBASE(i));
      buckets[b].push_back(number);
    }

    int counter = 0;
    for (int row = 0; row < BASE; ++row)
      for (int col = 0; col < buckets[row].size(); ++col, ++counter)
        numbers[counter] = buckets[row][col];
  }
}

int main() {
  vector<int> numbers = {0x101, 0x10, 0x0};//{0, 123, 888, 912, 709, 20, 901};
  in_place_radix_sort(numbers, 3);
  for (auto num : numbers)
    cout << num << " ";
}