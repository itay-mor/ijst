//
// Created by Itay Mor on 27/09/2023.
//

#include <bits/stdc++.h>

using namespace std;
using ldouble = float; //long double;

vector<ldouble> read_heights(size_t size) {
  vector<ldouble> return_vec(size + 2, numeric_limits<int64_t>::max());
  for (size_t i = 1; i <= size; i++) {
    cin >> return_vec[i];
  }

  return return_vec;
}
vector<ldouble> read_vector(size_t size) {
  vector<ldouble> return_vec(size);
  ldouble input;
  for (size_t i = 0; i < size; i++) {
    cin >> input;
    return_vec[i] = input;
  }

  return return_vec;
}

void run_ravioli_abc() {
  int n;
  cin >> n;

  auto heights = read_heights(n);
  auto new_heights = heights;
  int64_t curr_raviolis_num = 1;
  vector<int64_t> raviolis(n + 2, 0);

  while (true) {
    bool found_min_point = false;
    for (int i = 1; i <= n; ++i) {
      if (heights[i] <= heights[i - 1] && heights[i] <= heights[i + 1] && raviolis[i] == 0) {
        new_heights[i] = numeric_limits<ldouble>::max();
        raviolis[i] = curr_raviolis_num;
        found_min_point = true;
      }
    }
    heights = new_heights;
    if (!found_min_point) break;
    curr_raviolis_num++;
  }
  int64_t sum = 0;
  for (auto raviolis_num : raviolis) {
    sum += raviolis_num;
  }

  cout << sum;
}

void run_ravioli_abcd() {
  int n;
  cin >> n;

  auto heights = read_heights(n);

  // Finding maximums:
  vector<int> maximums_indexes = {0};
  for (int i = 1; i < n + 1; i++) {
    if (heights[i] == min({heights[i - 1], heights[i], heights[i + 1]})) {
      maximums_indexes.push_back(i);
    }
  }
  maximums_indexes.push_back(n + 1);

}

vector<ldouble> read_vector2(size_t size) {
  vector<ldouble> return_vec(size + 1, 0);
  for (size_t i = 0; i < size; i++) {
    cin >> return_vec[i];
  }

  return return_vec;
}

int64_t min_raviolis_num(const vector<ldouble>& heights) {
  size_t n = heights.size();
  int64_t counter = 0;
  if (n < 2) {
    return 1;
  }
  bool descending = heights[1] < heights[0];
  int64_t last_extremum = numeric_limits<int64_t>::min();
  int64_t min_raviolis_num = last_extremum;

  for (int i = 0; i < n; ++i) {
    counter++; // 1 2 3
    min_raviolis_num += counter; // 1  3  6
    if (i == n - 1 || (heights[i + 1] < heights[i]) != descending) {
      min_raviolis_num -= min(counter, last_extremum);
      last_extremum = descending ? 1 : counter;
      descending = (heights[i + 1] < heights[i]);

      counter = 1;
      min_raviolis_num += counter;
    }

    if (heights[i] == heights[i + 1]) {
      counter = 0;
    }
  }
  min_raviolis_num--;
  return min_raviolis_num;
}

int64_t run_ravioli_inplace() {
  size_t n;
  cin >> n;
  int64_t counter = 0;
  ldouble curr, next = numeric_limits<ldouble>::max();
  int64_t last_extremum = numeric_limits<int64_t>::min();
  int64_t min_raviolis_num = last_extremum;
  bool descending;

  for (int i = 0; i < n; ++i) {
    curr = next;
    cin >> next;
    if (i == 0) {
      continue;
    } else if (i == 1) {
      descending = next < curr;
    }

    counter++; // 1 2 3
    cerr << counter << endl;
    min_raviolis_num += counter; // 1  3  6
    if (i == n - 1 || (next < curr) != descending) {
      min_raviolis_num -= min(counter, last_extremum);
      last_extremum = descending ? 1 : counter;
      descending = (next < curr);

      counter = 1;
      min_raviolis_num += counter;
    }

    if (curr == next) {
      counter = 0;
    }
  }
  min_raviolis_num--;
  return (n >= 2) ? min_raviolis_num : 1;
}

void run_ravioli_abcd2() {
  int n;
  cin >> n;

  auto heights = read_vector(n);

  cout << min_raviolis_num(heights);
}

void main1() {
  constexpr ldouble K = 0;
  cout << min_raviolis_num({1, 2, 1, 2, 3, 1, 1}) << endl; // 3
//  cout << min_raviolis_num({1, 2, 3, 2, 5, 2, 5, 6}) << endl; // 15
//  //                               1  2  3  1  2  1  2  3   = 20
//  cout << min_raviolis_num({1, 2, 3, 4}) << endl; // 10
//  cout << min_raviolis_num({4, 3, 2, 1}) << endl; // 10
//  cout << min_raviolis_num({1, 2, 1}) << endl; // 4
//  cout << min_raviolis_num({2, 1, 2}) << endl; // 5
//  cout << min_raviolis_num({2, 1, 2, 1, 2, 1}) << endl; // 9
}

void main2() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << run_ravioli_inplace();
}

int main() {
  main2();
}