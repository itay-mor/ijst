//
// Created by Itay Mor on 02/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> dist;

int dfs(int node = 1) {
  if (node == n) return dist[node] = 1;
  int max_route = -2;
  for (auto nei : graph[node]) {
    if (dist[nei] == -2) dfs(nei);
    if (dist[nei] == -1) continue;
    max_route = max(dist[nei] + 1, max_route);
  }
  if (max_route == -2) return dist[node] = -1;

  return dist[node] = max_route;
}

int main() {
  cin >> n >> m;
  graph.resize(n+1);
  dist.assign(n+1, -2);
  int a, b;
  while (m--) {
    cin >> a >> b;
    graph[a].push_back(b);
  }
  if (dfs() == -1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << dist[1] << '\n';
  int curr_node = 1;
  while (curr_node != n) {
    cout << curr_node << " ";
    for (auto nei : graph[curr_node]) {
      if (dist[nei] == dist[curr_node] - 1) {
        curr_node = nei;
        break;
      }
    }
  }
  cout << curr_node;
}