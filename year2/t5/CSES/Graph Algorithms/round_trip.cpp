//
// Created by Itay Mor on 19/01/2024.
//
#include <bits/stdc++.h>
#define TMP 1
#define VIS 2

using namespace std;

vector<int> mark;
vector<vector<int>> graph;
vector<int> circle;

bool dfs(int node, vector<int>& prefix) {
  if (mark[node] == VIS) return false;
  if (mark[node] == TMP) { // found circle
    circle.push_back(node);
    for (int i = prefix.size() - 1; prefix[i] != node; --i)
      circle.push_back(prefix[i]);
    circle.push_back(node);
    if (circle.size() < 4) {
      circle.clear();
      return false;
    }
    return true;
  }

  prefix.push_back(node);
  mark[node] = TMP;

  for (int nei : graph[node])
    if(dfs(nei, prefix)) return true;

  mark[node] = VIS;
  prefix.pop_back();
  return false;
}

void round_trip() {
  vector<int> prefix = {};
  for (int i = 1; i < graph.size(); ++i) {
    if (!dfs(i, prefix)) continue;

    reverse(circle.begin(), circle.end());
    cout << circle.size() << endl;
    for (auto e : circle)
      cout << e << " ";

    return;
  }
  cout << "IMPOSSIBLE";

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
    graph[b].push_back(a);
  }

  round_trip();
}