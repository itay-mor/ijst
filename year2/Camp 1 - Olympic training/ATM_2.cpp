//
// Created by Itay Mor on 21/09/2023.
//
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

using ldouble = long double;

vector<ldouble> read_vector(size_t size) {
  vector<ldouble> return_vec(size);
  ldouble temp;
  for (size_t i = 0; i < size; i++) {
    cin >> temp;
    return_vec[i] = temp;
  }

  return return_vec;
}

void run_brut_force() {
  int64_t n;
  cin >> n;
  ldouble s;
  cin >> s;
  vector<ldouble> handles = read_vector(n);

  ldouble minimal_diff = 10*10*10 + 1;
  ldouble curr_diff;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {
      for (size_t k = 0; k < n; k++) {
        curr_diff = abs((handles[i] + handles[j] + handles[k] - s));
        if (curr_diff < minimal_diff) minimal_diff = curr_diff;
      }
    }
  }

  cout <<minimal_diff;
}

void solve() {
  int64_t n;
  cin >> n;
  ldouble s;
  cin >> s;
  vector<ldouble> handels = read_vector(n);
  sort(handels.begin(), handels.end());

  ldouble minimal_diff = (max(abs(handels[n-1]*3) - s, abs(handels[0]*3 - s)));
  ldouble curr_diff;


  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n; ++j) {

      ldouble reminder = s - handels[i] - handels[j];

      auto lower = lower_bound(handels.begin(), handels.end(), reminder);
      auto upper = upper_bound(handels.begin(), handels.end(), reminder);

      curr_diff = min(
          abs(s - (handels[i] + handels[j] + *lower)),
          abs(s - (handels[i] + handels[j] + *upper))
          );
      if (curr_diff < minimal_diff) minimal_diff = curr_diff;
      if (minimal_diff == 0) break;
    }
  }

//  if (minimal_diff - (int64_t) minimal_diff == 0) {
//    cout << (int64_t) minimal_diff;
//    return;
//  }
//
//  if (minimal_diff * 10 - (int64_t) (minimal_diff*10) == 0) {
//    printf("%.1Lf", minimal_diff);
//  }
//  printf("%.2Lf", minimal_diff);

cout << setprecision(2) << minimal_diff;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  solve();

}
