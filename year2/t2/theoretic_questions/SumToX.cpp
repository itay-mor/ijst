//
// Created by Itay Mor on 03/11/2023.
//
#include <bits/stdc++.h>

using namespace std;

bool alg1(vector<int> numbers, int x){
  sort(numbers.begin(), numbers.end());
  auto left_it = numbers.begin(), right_it = numbers.end() - 1;
  while (right_it >= left_it) {
    if (*left_it + *right_it > x)
      right_it--;
    else if (*left_it + *right_it < x)
      left_it++;
    else
      return true;
  }
  return false;
}

bool alg2(vector<int> numbers, int x) {
  sort(numbers.begin(), numbers.end());
  bool ans = false;
  int lower_index = (int) (lower_bound(numbers.begin(), numbers.end(),x/2) - numbers.begin());

  for (int i = 0; i <= lower_index; ++i)
    ans += binary_search(numbers.begin(), numbers.end(), x-numbers[i]);


  return ans;
}

int main() {
  auto numbers = {1, 8 , 0, 17, -8};
  cout << "alg1: ";
  if (alg1(numbers, 18))
    cout << "true" << endl;
  else
    cout << "false" << endl;

  cout << "alg2: ";
  if (alg2(numbers, 18))
    cout << "true" << endl;
  else
    cout << "false" << endl;
}