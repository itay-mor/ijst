//
// Created by Itay Mor on 07/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

// photographer: <end_of_session, start_of_session>
int solve(vector<pair<int, int>>& photographers, multiset<int>& flamingos) {
  sort(photographers.begin(), photographers.end());
  int ans = 0;
  for (auto photographer : photographers) {
    auto it = flamingos.lower_bound(photographer.second);
    if (it == flamingos.end()) continue;
    if (*it > photographer.first) continue;
    flamingos.erase(it);
    ans++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int c, n; cin >> c >> n;
  multiset<int> flamingos;
  vector<pair<int, int>> photographers(n);
  int temp;
  for (int i = 0; i < c; ++i) {
    cin >> temp;
    flamingos.insert(temp);
  }

  for (auto& photographer : photographers)
    cin >> photographer.second >> photographer.first;

  cout << solve(photographers, flamingos);
}