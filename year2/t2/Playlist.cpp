//
// Created by Itay Mor on 25/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  int64_t temp;
  for (size_t i = 0; i < size; i++) {
    cin >> temp;
    return_vec[i] = temp;
  }

  return return_vec;
}

void run_playlist() {
  int64_t n;
  cin >> n;

  auto songs = read_vector(n);

  map<int64_t, vector<int64_t>::iterator> m = {{*songs.begin(), songs.begin()}};

  auto left_it = songs.begin();
  auto right_it = songs.begin();

  int64_t max_length = 0, curr_length = 1;
  while (right_it < songs.end()-1) {
    right_it++;
    auto it = m.find(*right_it);
    if (it != m.end()) {
      left_it = it->second + 1;
      m.clear();
      for (auto i = left_it; i <= right_it; i ++) {
        m.emplace(*i, i);
      }
    }
    m.emplace(*right_it, right_it);

    curr_length = right_it-left_it + 1;
    if (curr_length > max_length) {
      max_length = curr_length;
    }
  }

  cout << max_length;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  run_playlist();
}