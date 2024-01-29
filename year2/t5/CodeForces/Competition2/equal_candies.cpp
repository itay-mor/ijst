//
// Created by Itay Mor on 27/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  int n, min_box, ans;
  vector<int> boxes;
  while (t--) {
    cin >> n;
    min_box = numeric_limits<int>::max();
    ans = 0;
    boxes.resize(n);
    for (auto& box : boxes)
      cin >> box, min_box = min(min_box, box);

    for (auto box : boxes)
      ans += box - min_box;

    cout << ans << '\n';
  }
}