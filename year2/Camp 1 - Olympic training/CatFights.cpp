//
// Created by Itay Mor on 21/09/2023.
//
#include <iostream>
#include <cstdint>
#include <bitset>
#include <vector>

#define POW2(x) 1>>x

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  int temp;
  for (size_t i = 0; i < size; i++) {
    cin >> temp;
    return_vec[i] = temp;
  }

  return return_vec;
}

void run_brut_force() {
  int64_t n, k;
  cin >> k >> n;
  vector<int64_t> buckets();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}