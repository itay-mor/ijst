//
// Created by Itay Mor on 19/01/2024.
//
#include <bits/stdc++.h>
#define TMP 1
#define VIS 2

using namespace std;

vector<int> mark;
vector<vector<int>> graph;
vector<int> sorted;

bool dfs(int node) {
  if (mark[node] == VIS) return true;
  if (mark[node] == TMP) return false;

  mark[node] = TMP;

  for (int nei : graph[node])
    if(!dfs(nei)) return false;

  mark[node] = VIS;
  sorted.push_back(node);
  return true;
}

void topological_sorting() {
  for (int i = 1; i < graph.size(); ++i) {
    if (!dfs(i)) {
      cout << "IMPOSSIBLE";
      return;
    }
  }

  for (int i = graph.size() - 2; i >= 0; --i){
    cout << sorted[i] << " ";
  }

}

void topological_sorting2() {
  queue<int> zero_in_degree;
  vector<int> in_degree(graph.size() + 1);
  for (int i = 1; i <= graph.size(); ++i) {
    in_degree[i] = graph[i].size();
    if (in_degree[i] == 0) zero_in_degree.push(i);
  }

  while (!zero_in_degree.empty()) {
    auto v = zero_in_degree.front();
    zero_in_degree.pop();
    sorted.push_back(v);

    for (auto adj : graph[v])
      if (--in_degree[adj] == 0)
        zero_in_degree.push(adj);

  }
  if (sorted.size() != graph.size() - 1)
    cout << "IMPOSSIBLE";
  else
    for (auto v : sorted)
      cout << v << " ";


}

int main() {
  int n, m;
  cin >> n >> m;
  graph.resize(n+1);
  mark.assign(n + 1, 0);
  int a, b;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    graph[a].push_back(b);
  }
  topological_sorting();
}