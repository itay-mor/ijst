//
// Created by Itay Mor on 04/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

long long pow2(int n) {
  static long long pows[20] = {
      1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 5096, 10192, 20384
  };

  return pows[n];
}

int waist(const vector<int>& heights, bitset<20> limbo_heights, int init_h) {
  int w = 0, x = init_h, curr_w;
  for (int i = 0; i < heights.size(); ++i) {
    if (limbo_heights[i]) x = heights[i];
    curr_w = x - heights[i];
    if (curr_w < 0) return -1;
    w += curr_w;
  }
  return w;
}

int waist2(const vector<int>& heights, int init_h, int change_time, int change) {
  int w = 0, x = init_h, curr_w;
  for (int i = 0; i < heights.size(); ++i) {
    if (i == change_time) x = change;
    curr_w = x - heights[i];
    if (curr_w < 0) return -1;
    w += curr_w;
  }
  return w;
}

int brut_force(int n, int k, int init_h, const vector<int>& heights) {
  bitset<20> limbo_heights;
  int min_waist = numeric_limits<int>::max(), curr_w;
  for (int i = 0; i < pow2(n); ++i) {
    limbo_heights = bitset<20>(i);
    if (limbo_heights.count() != k) continue;
    curr_w = waist(heights, limbo_heights, init_h);
    if (curr_w < 0) continue;
    min_waist = min(min_waist, curr_w);
  }
  return min_waist;
}

int brut_force2(int n, int k, int init_h, const vector<int>& heights) {
  int min_waist = numeric_limits<int>::max(), curr_waist, mini = numeric_limits<int>::max();
  for (int i = 0; i < n; ++i) {
    for (auto height : heights) {
      curr_waist = waist2(heights, init_h, i, height);
      if (curr_waist < 0) continue;
      min_waist = min(min_waist, curr_waist);
    }
  mini = min(mini, min_waist);
  }
  return mini;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> heights(n);
  for (auto& h : heights)
    cin >> h;

  if (k != 1) {
    cout << "I'm not solving this subtask";
    assert("I'm not solving this subtask");
  }
  int min_waist = numeric_limits<int>::max();
  for (auto h : heights) {
    min_waist = min(min_waist, brut_force2(n, k, h, heights));
  }

  cout << min_waist;
}