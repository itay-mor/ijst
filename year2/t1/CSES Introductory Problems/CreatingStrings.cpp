//
// Created by Omer on 08/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

int choose(int n, int k) {
  if (k == 0 || ((k == 1) && (n == 1))) return 1;
  
  k = min(k, n - k);
  
  int fact_k = 2;
  for (int i = 3; i <= k; ++i) fact_k *= i;
  
  if (k == 1) fact_k = 1;
  
  int n_choose_k = 1;
  for (int i = (n - k + 1); i <= n; ++i) n_choose_k *= i;
  
  n_choose_k /= fact_k;
  
  return n_choose_k;
}

void print_permutation_number(const string& s) {
  int n = s.length();
  vector<int> char_count(26, 0);
  for (auto c: s) char_count[c - 'a']++;
  
  int permutations_number = 1, empty_indexes = n;
  for (auto count : char_count) {
    if (count == 0) continue;
    permutations_number *= choose(empty_indexes, count);
    empty_indexes -= count;
  }
  
  
  cout << permutations_number << endl;
}

void run_creating_strings(array<int, 26>& char_counts, const string& prefix = "") {
  string to_print;
  // TODO: Add stop condition.
  for (int i = 0; i < char_counts.size(); ++i) {
    if (char_counts[i] > 0) {
      string new_prefix = prefix + (char) (i + 'a');
      char_counts[i]--;
      run_creating_strings(char_counts, new_prefix);
      char_counts[i]++;
    }
    
  }
}

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
}