//
// Created by Itay Mor on 25/09/2023.
// https://cses.fi/problemset/task/1141
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

  const auto songs = read_vector(n);

  set<int64_t> used_ids = {*songs.begin()};

  auto left_it = songs.begin();
  auto right_it = songs.begin();

  int64_t max_length = 1, curr_length = 1;
  while (++right_it < songs.end()) {
    auto it = used_ids.find(*right_it);
    if (it != used_ids.end()) {
      while (true) {
        if((*left_it) == *right_it) {
          used_ids.erase(*left_it);
          left_it++;
          break;
        }
        used_ids.erase(*left_it);
        left_it++;
      }
    }
    used_ids.emplace(*right_it);

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