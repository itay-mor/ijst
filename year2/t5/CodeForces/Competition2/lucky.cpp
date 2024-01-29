//
// Created by Itay Mor on 27/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  string ticket;
  while (t--) {
    cin >> ticket;
    if (ticket[0] + ticket[1] + ticket[2] == ticket[3] + ticket[4] + ticket[5])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}