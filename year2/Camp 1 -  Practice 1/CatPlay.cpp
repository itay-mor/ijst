//
// Created by Itay Mor on 03/10/2023.
//

#include <bits/stdc++.h>

constexpr int64_t MODULUS  = 10000019;

using namespace std;

int64_t modular_power(int64_t base, int64_t exponent, int64_t modulus) {
  int64_t ans = 1;
  for (; exponent > 0; exponent >>= 1) {
    if (exponent % 2) {
      ans *= base;
      ans %= modulus;
    }
    base *= base;
    base %= modulus;
  }
  ans %= modulus;
  return ans;
}

void run_cat_play() {
  int64_t n; cin >> n;
  int64_t a, b, c;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b >> c;

    /*
     * From Fermat's little theorem:
     *    a^b^c === 1 * a^b^c === a^(MODULUS-1) * a^b^c === a^(b^c + MODULUS -1)      (mod MODULUS)
     *    ==> a^b^c (mod MODULUS) = a^(b^c   (mod MODULUS - 1))   (mod MODULUS)
     */
    cout << modular_power(a, modular_power(b, c, MODULUS - 1), MODULUS) << "\n";

  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  run_cat_play();
}