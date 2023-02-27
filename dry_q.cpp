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

std::chrono::_V2::steady_clock::rep benchmark(unsigned int n, unsigned int m,
                                              unsigned int count = 100000) {
  std::chrono::_V2::steady_clock::rep time;
  vector<rational> rationals;
  rationals.reserve(n);
  for (; count > 0; count--) {
    rationals.clear();
    for (int i = 0; i < n; i++) {
      int numerator = rand() % (2 * n - 1) + (1 - n);
      int denominator = rand() % (m - 1) + 1;
      rationals.emplace_back(numerator, denominator);
    }

    auto before = chrono::steady_clock::now();
    vector<rational> sorted = sort(rationals, m);
    auto after = chrono::steady_clock::now();

    time += chrono::duration_cast<chrono::nanoseconds>(after - before).count();
  }
  return time;
}

void benchmark_test_n() {
  cout << "n, time" << endl;
  std::chrono::_V2::steady_clock::rep first = 0;
  for (int n = 50; n < 2000; n++) {
    auto time = benchmark(n, 30);
    if (first == 0) {
      first = time;
    };
    cout << n << ", " << time - first << endl;
  }
}

void benchmark_test_m() {
  cout << "m, time" << endl;
  std::chrono::_V2::steady_clock::rep first = 0;
  for (int m = 30; m < 2000; m++) {
    auto time = benchmark(3000, m);
    if (first == 0) {
      first = time;
    };
    cout << m << ", " << time - first << endl;
  }
}

int main() {
  vector<rational> rationals;
  srand(time(0));

  benchmark_test_n();
  benchmark_test_m();
  return 0;
  int m = 5, n = 23;
  for (int i = 0; i < n; i++) {
    int numerator = rand() % (2 * n - 1) + (1 - n);
    int denominator = rand() % (m - 1) + 1;
    rationals.push_back({numerator, denominator});
    cout << numerator << '/' << denominator << ", ";
  }
  cout << endl << endl;

  // vector<rational> rationals = {
  //     {1, 3}, {3, 3}, {-6, 4}, {5, 1}, {3, 3}, {1, 1}, {2, 4},
  // };

  auto before = chrono::steady_clock::now();
  vector<rational> sorted = sort(rationals, m);
  auto after = chrono::steady_clock::now();

  auto time =
      chrono::duration_cast<chrono::nanoseconds>(after - before).count();

  for (const rational& r : sorted) {
    auto [n, d] = r;
    cout << n << '/' << d << ", ";
  }
  cout << endl
       << endl
       << "Time: " << static_cast<long double>(time) / 1000000000 << " seconds."
       << endl;
}