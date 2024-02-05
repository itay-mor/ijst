//
// Created by Itay Mor on 04/02/2024.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ll n, t;
  cin >> n >> t;
  vector<pair<ll, ll>> children(n);
  vector<ll> final_pos(n + 1);
  final_pos[n] = numeric_limits<ll>::max();
  for (ll i = 0; i < n; ++ i)
    cin >> children[i].first >> children[i].second;

  sort(children.begin(), children.end());
  ll x, v;
  for (ll i = n - 1; i >= 0 ; --i) {
    x = children[i].first;
    v = children[i].second;
    final_pos[i] = min(t*v + x, final_pos[i+1]);
  }

  ll ans = 1;
  for (ll i = 1; i < n; ++i) {
    if (final_pos[i] != final_pos[i-1]) ans++;
  }
  cout << ans;
}