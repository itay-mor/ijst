//
// Created by Itay Mor on 26/01/2024.
//
//
// Created by Itay Mor on 26/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  int n, length, quality, winner, winner_quality;
  while (t--) {
    winner_quality = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> length >> quality;
      if (length <= 10 && quality > winner_quality)
        winner = i, winner_quality = quality;
    }
    cout << winner << "\n";
  }
}