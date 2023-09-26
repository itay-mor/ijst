//
// Created by Itay Mor on 26/09/2023.
// https://cses.fi/problemset/task/1629/
//

#include <bits/stdc++.h>

using namespace std;

using Movie = pair<int64_t, int64_t>;

vector<Movie> read_movies(size_t size) {
  Movie input_movie;
  vector<Movie> movies(size);
  for (size_t i = 0; i < size; ++i) {
    cin >> input_movie.first >> input_movie.second;
    movies[i] = input_movie;
  }

  return movies;
}

void run_movie_festival() {
  int64_t n;
  cin >> n;
  auto movies = read_movies(n);
  vector<int64_t> dp(n + 1, 0);
  sort(movies.begin(), movies.end());

  for (int64_t i = n - 1; i >= 0; i--) {
    auto [start_hour, end_hour] = movies[i];
    auto next_available_movie_index = lower_bound(movies.begin(),
                                                  movies.end(),
                                                  Movie(end_hour, 0))
        - movies.begin();
    dp[i] = max(1 + dp[next_available_movie_index], dp[i + 1]);
  }

  cout << dp[0];
}

int main() {
  run_movie_festival();
}