//
// Created by Itay Mor on 07/01/2024.
//
#include <bits/stdc++.h>
using namespace std;

using person = pair<int, int>;

int solve(vector<person>& costumers) {
  set<int> waitlist;
  vector<pair<int, int>> sorted_costumers; // <start, i>
  for (int i = 0; i < costumers.size(); ++i)
    sorted_costumers.emplace_back(costumers[i].first, i);

  sort(sorted_costumers.begin(), sorted_costumers.end());


  pair<int, int> curr_sitter;
  for (auto costumer : sorted_costumers) {

  }
}

int solve_a(const vector<pair<int64_t, int>>& costumers) {
  int ans = 0, curr_start, curr_end = 0, prev_end;

  for (auto c : costumers) {
    prev_end = curr_end;
    curr_start = c.first;
    curr_end = c.second + max(curr_start, prev_end);
    ans = max(ans, prev_end - curr_start);
  }

  return ans;
}

int solve_b(vector<pair<int64_t, int>>& costumers) {
  reverse(costumers.begin(), costumers.end());
  stack<pair<int, int>> s;
  int i = 0;
  int ans = 0, curr_start, curr_end = 0, prev_end;
  for (int j = 0; j < costumers.size(); ++j) {
    s.emplace(costumers[j]);
    prev_end = curr_end;
    curr_start = s.top().first;
    curr_end = s.top().second + max(curr_start, prev_end);
    s.pop();
    while (i < costumers.size() - 1 && costumers[i + 1].first <= curr_end) {
      s.emplace(costumers[i+1]);
      i++;
    }
    ans = max(ans, prev_end - curr_end);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int64_t, int>> costumers(n);
  for (auto& c : costumers)
    cin >> c.first >> c.second;
  cout << solve_a(costumers);
}