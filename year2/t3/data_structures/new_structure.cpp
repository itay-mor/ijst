//
// Created by Itay Mor on 26/11/2023.
//
#include "new_structure.h"
#include <iostream>

int main() {
  mean_set<int> ms;
  ms.push(4);
  ms.push(10);
  ms.push(20);
  std::cout << ms.get_mean() << " ";
  ms.pop(10);
  std::cout << ms.get_mean();
}