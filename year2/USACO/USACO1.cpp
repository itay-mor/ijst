//
// Created by Itay Mor on 18/12/2023.
//

#include <bits/stdc++.h>
#define FASTIO ios_base::  ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

using namespace std;

int main()
{
  FASTIO
  int64_t n, m; cin >> n >> m;
  vector<int64_t> cows(n);
  vector<pair<int64_t, int64_t>> canes(m);

  for (auto& cow : cows)
    cin >> cow;
  for (auto& [cane_start, cane_end] : canes) {
    cane_start = 0;
    cin >> cane_end;
    for (auto& cow : cows) {
      int64_t temp = cane_start;
      cane_start = max(min(cow, cane_end), cane_start);
      cow += (min(cow - temp, cane_end - temp) > 0) ? min(cow - temp, cane_end - temp) : 0;
    }
  }
// for (auto& [cane_start, cane_end] : canes) {
//   for (auto& cow : cows) {
//     int64_t temp = cane_start;
//     cane_start = max(min(cow, cane_end), cane_start);
//     cow += (min(cow - temp, cane_end - temp) > 0) ? min(cow - temp, cane_end - temp) : 0;
//   }
// }
 for (auto& cow : cows)
   cout << cow << endl;
}