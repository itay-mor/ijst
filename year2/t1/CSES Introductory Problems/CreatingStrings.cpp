//
// Created by Itay on 08/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

using CharCounts = array<uint8_t, 26>;

CharCounts create_char_counts(const string& s) {
  CharCounts char_counts{};

  for (char c : s) {
    char_counts[c - 'a']++;
  }

  return char_counts;
}

/*
 *  Calculating n choose k using:
 *  (n choose k) = (n!)/((n-k)! * k!)
 *  -----------------------------------------
 *
 *  Gets: int n,k
 *  Returns n choose k
 */
size_t choose(size_t n, size_t k) {
  k = min(k, n - k);

  if (k == 0)
    return 1; // (n choose 0) = 1, (n choose n) --> (n choose 0) --> 1.

  size_t fact_k = 2;
  for (size_t i = 3; i <= k; ++i)
    fact_k *= i;

  if (k == 1)
    fact_k = 1;

  size_t n_choose_k = 1;
  for (auto i = (n - k + 1); i <= n; ++i)
    n_choose_k *= i;

  n_choose_k /= fact_k;

  return n_choose_k;
}

/*
 * Calculating the number of permutations of string s and prints it to the
 * stdout stream
 * -------------------------------------------------------------------------------------
 *
 * Gets: string& s (by reference)
 * Returns: void
 */
void print_permutation_number(const string& s) {
  CharCounts char_count{};
  for (auto c : s)
    char_count[c - 'a']++;

  size_t permutations_number = 1, empty_indexes = s.length();
  for (auto count : char_count) {
    if (count == 0)
      continue;
    permutations_number *= choose(empty_indexes, count);
    empty_indexes -= count;
  }

  cout << permutations_number << endl;
}

void run_creating_strings(CharCounts& char_counts, const string& prefix = "") {
  string to_print;

  // Calculating the sum of the std::array.
  int char_counts_sum = 0;
  for (auto counter : char_counts) {
    char_counts_sum += counter;
  }

  // Stop condition.
  if (char_counts_sum == 0) {
    cout << prefix << endl;
    return;
  }

  /*
   * For each letter in s:
   *   if there are more than zero of it:
   *     call run_creating_strings with prefix: (prefix + letter), on the rest of the string
   */
  for (int i = 0; i < char_counts.size(); ++i) {
    if (char_counts[i] <= 0) continue;

    string new_prefix = prefix + (char) (i + 'a');
    char_counts[i]--;
    run_creating_strings(char_counts, new_prefix);
    char_counts[i]++;
  }
}

int main() {
  string s;
  cin >> s;
  auto char_counts = create_char_counts(s);
  print_permutation_number(s);
  run_creating_strings(char_counts);
}
