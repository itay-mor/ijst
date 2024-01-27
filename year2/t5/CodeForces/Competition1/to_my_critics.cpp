//
// Created by Itay Mor on 26/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t; cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    if (a + b >= 10 || a + c >= 10 || b + c >= 10)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}