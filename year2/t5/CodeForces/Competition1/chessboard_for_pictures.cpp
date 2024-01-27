//
// Created by Itay Mor on 26/01/2024.
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll squares(const vector<ll>& pictures, ll w) {
  ll ans = 0;
  for (auto s : pictures) {
    ans += (s + 2*w)*(s + 2*w);
  }
  return ans;
}

ll find_w(const vector<ll>& pictures, ll c, ll n) {
  ll low = 0, high = (ll) sqrt(c/n), guess, s;
  while (true) {
    guess = (low + high)/2;
    s = squares(pictures, guess);
    if (s == c) return guess;
    if (s > c) high = guess - 1;
    if (s < c) low = guess + 1;
  }

}

int main() {
  int t; cin >> t;
  ll n, c;
  vector<ll> pictures;
  while (t--) {
    cin >> n >> c;
    pictures.resize(n);
    for (auto& s : pictures)
      cin >> s;
    cout << find_w(pictures, c, n) << '\n';
  }
}