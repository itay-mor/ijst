//
// Created by Itay Mor on 25/11/2023.
//
#include <list>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

using num = unsigned long long; // unsigned
num n = 0; // global variable


list<num> primes() {
  list<num> plist;
  vector<bool> is_prime(n, true);
  for (num i = 2; i < sqrt(n); ++i) {
    if (is_prime[i]) {
      for (num j = i * i; j < n; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (num i = 2; i < n ; i++) {
    if (is_prime[i]) {
      plist.push_back(i);
    }
  }
  return plist;
}

int main() {
  cin >> n;
  auto all_primes = primes();
  for (auto p : all_primes) cout << p << "\n";
}