//
// Created by Itay Mor on 21/09/2023.
//
#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t m;
  cin >> m;

  int64_t query;

  for (int64_t i = 0; i < m; ++i) {
    cin >> query;
    if (query % 2 == 0) cout << "F\n";
    else cout << "S\n";
  }
}