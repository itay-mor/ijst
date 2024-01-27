//
// Created by Itay Mor on 22/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int min_jumps(const vector<int>& A) {
  auto n = A.size();
  int jump_end = 0;

  int i = 0, jumps = 0;
  while (jump_end < n-1) {
    int max_jump = 0;
    for (; i <= jump_end; ++i) max_jump = max(max_jump, A[i]);
    if (max_jump <= 0) return -1;
    jump_end = i + max_jump-1;
    jumps++;
  }

  return jumps;
}

int main() {
  cout << min_jumps({1, 2, -2, 3});
}