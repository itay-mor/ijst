//
// Created by Itay Mor on 28/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int movie_festival_2(vector<pair<int, int>>& movies, int k) {
  std::sort(movies.begin(), movies.end());
  multiset<int> free_times;
  for (int i = 0; i < k; ++i)
    free_times.insert(0);

  int result = 0;
  for (auto [end_time, start_time] : movies) {
    auto it = free_times.upper_bound(start_time);
    if (it == free_times.begin()) continue;
    --it;
    free_times.erase(it);
    free_times.insert(end_time);
    result++;
  }
  return result;
}

int main() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> movies(n);
  for (auto& [end_time, start_time] : movies)
    cin >> start_time >> end_time;
  cout << movie_festival_2(movies, k);


}