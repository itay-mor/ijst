//
// Created by Itay Mor on 07/01/2024.
//
#include <bits/stdc++.h>
#define MOD 1'000'000'009

using namespace std;

bool is_legal(string str, bitset<20> b) {
  stack<char> s_green, s_red;
  char c;
  int bit;
  for (int i = 0; i < str.size(); i++) {
    c = str[i];
    bit = b[i];
    if (bit == 0) {
      if (c == '(') s_green.push(c);
      else if (s_green.empty()) return false;
      else s_green.pop();
    } else {
      if (c == '(') s_red.push(c);
      else if (s_red.empty()) return false;
      else s_red.pop();
    }
  }
  return s_green.empty() && s_red.empty();
}

int solve(const string& str) {
  int n = str.size();
  int solution = 0;
  bitset<20> b;
  for (int64_t i = 0; i < pow(2, n); ++i) {
    b = bitset<20>(i);
    if (is_legal(str, b)) {
      solution++;
      solution %= MOD;
    }
  }
  return solution;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string str; cin >> str;
  cout << solve(str);
}