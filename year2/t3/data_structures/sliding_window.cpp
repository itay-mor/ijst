//
// Created by Itay Mor on 28/11/2023.
//
#include <iostream>
#include "stacks_queue.h"

#define N 10

int main() {
  int arr[N] = {};
  for (int& n : arr) std::cin >> n; // Scan arr from input.

  int k;
  std::cin >> k; // Scan k from input.

  stacks_queue<int> sq;
  for (int i = 0; i < k; ++i) sq.push(arr[i]); // Initialize queue to first k elements of arr.

  std::cout << "[0" << ", " << k - 1 << "]  -->  " << sq.minimum() << std::endl; //
  for (int i = k; i < N; ++i) {
    sq.push(arr[i]);
    sq.pop();
    std::cout << "[" << i - k + 1 << ", " << i << "]  -->  " << sq.minimum() << std::endl;
  }
}