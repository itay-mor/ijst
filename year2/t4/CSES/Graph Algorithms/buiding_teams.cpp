//
// Created by Itay Mor on 24/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> teams;

bool dfs(int curr_kid, int prev_kid = 0) {
  bool possible = true;
  for (auto friend_kid : graph[curr_kid]) {
    if (prev_kid == friend_kid) continue;

    if (teams[friend_kid] != 0) {
      if (teams[friend_kid] == teams[curr_kid])
        possible = false;
    }
    else {
      teams[friend_kid] = 3 - teams[curr_kid];
      if (!dfs(friend_kid, curr_kid)) possible = false;
    }
  }
  return possible;
}

int main() {
  int n, m;
  cin >> n >> m;
  graph = vector<vector<int>>(n + 1);
  teams = vector<int>(n + 1, 0);
  int kid1, kid2;
  for (int i = 0; i < m; ++i) {
    cin >> kid1 >> kid2;
    graph[kid1].push_back(kid2);
    graph[kid2].push_back(kid1);
  }
  bool possible = true;
  for (int kid = 1; kid <= n; ++kid) {
    if (teams[kid] != 0) continue;
    teams[kid] = 1;
    if (!dfs(kid)) possible = false;
  }
  if (!possible) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int i = 1; i <= n; ++i)
    cout << teams[i] << " ";
}