//
// Created by Itay Mor on 27/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  map<int, int> hist;
  int num;
  for (int i = 0; i < n; ++i) {
    cin >> num;
    hist[num]++;
  }

  for (auto key : hist) {
    if (key.second < k) hist.erase(key.first);
  }

  set<pair<int, int>> ranges;
  int cr = 0, cl = 0;
  auto curr_r = hist.begin(), curr_l = hist.begin();
  auto prev_r = curr_r;
  while (curr_r != hist.end() && curr_l != hist.end()) {
    if (curr_r->first - prev_r->first <= 1) {
      cr++;
      prev_r = curr_r, curr_r++;
    }
    else {
      ranges.emplace(cl, cr);
      cl = ++cr, curr_l = ++curr_r, prev_r = curr_r;
    }
  }

  auto it = ranges.end(); it--;
  cout << it->first << it->second;
}

int main() {
  int t; cin>> t;
  while (t--) {
    solve();
  }
}