//
// Created by Itay Mor on 14/12/2023.
//
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main() {
  vector<int> f(1000);
  f[0]=1;
  f[2]=2;
  for (int i = 0; i < 1000; i += 2) {
    for (int j = 0; j < i; j += 2) {
      f[i] += (f[j]%MOD*f[i-j]%MOD)%MOD;
    }
  }
  cout << f[1000-2];
}