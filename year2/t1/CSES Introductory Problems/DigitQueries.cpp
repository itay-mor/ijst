//
// Created by Itay Mor on 15/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int64_t n;
  cin >> n;
  
  int64_t i = 1;
  auto calc = 9;
  for (; calc < n && calc*10; ++i, calc = i * 9 * pow(10, n - 1)) {


  }
}