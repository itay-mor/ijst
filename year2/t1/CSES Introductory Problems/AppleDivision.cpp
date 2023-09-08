//
// Created by Omer on 08/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

using apple_pile = vector<int64_t>;

apple_pile read_apple_pile() {
  int n;
  cin >> n;
  
  apple_pile pile;
  pile.reserve(n);
  int64_t apple;
  for (int i = 0; i < n; ++i) {
    cin >> apple;
    pile.push_back(apple);
  }
  return pile;
}

int64_t run_apple_division(int n, const apple_pile &pile) {
  int64_t min_difference = 0;
  for (auto apple: pile) min_difference = abs(min_difference - apple);
  
  return min_difference;
}

int main() {
  auto pile = read_apple_pile();
  cout << run_apple_division(pile.size(), pile) << endl;
}
