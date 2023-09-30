//
// Created by Itay Mor on 28/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  for (size_t i = 0; i < size; i++) cin >> return_vec[i];

  return return_vec;
}


int64_t solve_apartments(vector<int64_t>& apartments, vector<int64_t>& applicants, const int64_t& max_diff) {
  int64_t max_applicants_num = 0;
  sort(apartments.begin(), apartments.end());
  sort(applicants.begin(), applicants.end());

  for (int64_t i = 0, j = 0; i < apartments.size() && j < applicants.size();) {
    if (abs(apartments[i] - applicants[j]) <= max_diff) {
      // Apartment fit.
      i++;
      j++;
      max_applicants_num++;
    } else if (apartments[i] - applicants[j] > max_diff) {
      // Apartment is too small.
      j++; // Moving to bigger apartment.
    } else {
      // Apartment is too big.
      i++; // Moving to next applicant.
    }
  }

  return max_applicants_num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, m, k;
  cin >> n >> m >> k;

  auto applicants = read_vector(n), apartments = read_vector(m);

  cout << solve_apartments(apartments, applicants, k);
}
