#include <time.h>  // For generation "random" seed.

#include <chrono>    // For calculating the running time.
#include <cstdlib>   // For gernerating random numbers.
#include <iostream>  // For input/output.
#include <tuple>     // For the fractions tuples: {numerator, denominator}.
#include <vector>    // For the buckets and the lists of rationals.

using namespace std;
using rational = tuple<int, unsigned int>;  // "Creating" rational type (tuple
                                            // of an int and an unsigned int).

vector<rational> merge(const vector<vector<rational>>& buckets) {
  if (buckets.size() == 1) {
    return buckets[0];
  }  // The stop condition.

  vector<vector<rational>> left;
  left.reserve(buckets.size() / 2);
  for (int i = 0; i < buckets.size() / 2; i++) {
    left.push_back(buckets[i]);
  }

  vector<vector<rational>> right;
  right.reserve(buckets.size() / 2);
  for (int i = buckets.size() / 2; i < buckets.size(); i++) {
    right.push_back(buckets[i]);
  }

  int idx_left = 0, idx_right = 0;

  vector<rational> merged_left = merge(left);
  vector<rational> merged_right = merge(right);

  vector<rational> merged;
  while (idx_left < merged_left.size() || idx_right < merged_right.size()) {
    if (idx_right >= merged_right.size()) {
      merged.push_back(merged_left[idx_left]);
      idx_left++;
      continue;
    } else if (idx_left >= merged_left.size()) {
      merged.push_back(merged_right[idx_right]);
      idx_right++;
      continue;
    }

    auto [l_numerator, l_denominator] = merged_left[idx_left];
    auto [r_numerator, r_denominator] = merged_right[idx_right];

    float rl = static_cast<float>(l_numerator) / l_denominator;
    float rr = static_cast<float>(r_numerator) / r_denominator;

    if (rl < rr) {
      merged.push_back(merged_left[idx_left]);
      idx_left++;
    } else {
      merged.push_back(merged_right[idx_right]);
      idx_right++;
    }
  }

  return merged;
}

vector<rational> sort(const vector<rational>& rationals, unsigned int m) {
  int n = rationals.size();  // Calculating n from rationals length.

  // Building the buckets for the numerators.
  vector<vector<rational>> nu_buckets(2 * n - 1);

  // Adding each rational into his appropriate bucket.
  for (const auto& r : rationals) {
    auto [numerator, _] = r;

    // We want rational with numerator 1-n to be in bucket[0].
    int index = numerator - (1 - n);

    nu_buckets[index].push_back(r);
  }

  // Building the buckets for the denominators.
  vector<vector<rational>> de_buckets(m - 1);

  // Adding each rational into his appropriate bucket.
  for (const vector<rational>& bucket : nu_buckets) {
    for (const rational& r : bucket) {
      auto [_, denominator] = r;
      int index = denominator - 1;
      de_buckets[index].push_back(r);
    }
  }

  // Each bucket is sorted, all we have to do is the merge the buckets.
  return merge(de_buckets);
}

int main() {
  vector<rational> rationals;
  srand(time(0));

  int m = 5, n = 23;
  cout << "BEFORE:" << endl;
  for (int i = 0; i < n; i++) {
    int numerator = rand() % (2 * n - 1) + (1 - n);
    int denominator = rand() % (m - 1) + 1;
    rationals.emplace_back(numerator, denominator);
    cout << numerator << '/' << denominator << ", ";
  }
  cout << endl << endl;

  auto before = chrono::steady_clock::now();
  vector<rational> sorted = sort(rationals, m);
  auto after = chrono::steady_clock::now();

  auto time =
      chrono::duration_cast<chrono::nanoseconds>(after - before).count();

  cout << "AFTER:" << endl;
  for (const rational& r : sorted) {
    auto [n, d] = r;
    cout << n << '/' << d << ", ";
  }
  cout << endl
       << endl
       << "Time: " << static_cast<long double>(time) / 1000000000 << " seconds."
       << endl;
}