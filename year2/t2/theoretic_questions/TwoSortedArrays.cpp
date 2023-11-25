//
// Created by Itay Mor on 03/11/2023.
//
#include <bits/stdc++.h>

using namespace std;

template<typename Num_T>
vector<Num_T> read_vector(size_t size) {
  vector<Num_T> vec(size);
  for (size_t i = 0; i < size; ++i)
    cin >> vec[i];

  return vec;
}

template<typename Num_T>
Num_T k_min_element(vector<Num_T> vec1, vector<Num_T> vec2, size_t k) {

  auto it1 = (vec1.size() > k) ? vec1.begin()+k : vec1.end(), it2 = (vec2.size() > k) ? vec2.begin()+k : vec2.end();
  while ((it1 - vec1.begin()) + (it2 - vec2.begin()) > k-2) {
    if (*(it1-1) < *(it2-1))
      it2 = lower_bound(vec2.begin(), vec2.end(), *(it1-1));
    else
      it1 = lower_bound(vec1.begin(), vec1.end(), *(it2-1));
  }

  return max(*it1, *it2);
}

int main() {
  size_t n, k;
  cin >> n >> k;

  auto vec1 = read_vector<int>(n);
  auto vec2 = read_vector<int>(n);
  if (n < k) {
    vector<int> to_add(k-n, numeric_limits<int>::max());
    vec1.insert(vec1.end(), to_add.begin(), to_add.end());
  }

  cout << k_min_element(vec1, vec2, k);
}