//
// Created by Itay Mor on 23/12/2023.
//
#include <bits/stdc++.h>
#define IMPOSSIBLE -1
using namespace std;

vector<vector<int>> graph;
vector<int> arrived_from;

int n, m;

void bfs() {
  queue<int> bfs;
  bfs.push(1);
  int curr;
  while (!bfs.empty()) {
    curr = bfs.front();
    bfs.pop();

    for (auto node : graph[curr]) {

      if (arrived_from[node] != IMPOSSIBLE) continue;
      arrived_from[node] = curr;

      if (node == n) return;
      bfs.push(node);
    }
  }
}

int main() {
  cin >> n >> m;
  arrived_from = vector<int>(n + 1, IMPOSSIBLE);
  graph = vector<vector<int>>(n + 1);
  int city1, city2;
  for (int i = 0; i < m; ++i) {
    cin >> city1 >> city2;
    graph[city1].push_back(city2);
    graph[city2].push_back(city1);
  }

  bfs();
  if (arrived_from[n] == IMPOSSIBLE) {
    cout << "IMPOSSIBLE";
    return 0;
  }

  stack<int> route;
  int maija = n;
  while (maija != 1) {
    route.push(maija);
    maija = arrived_from[maija];
  }
  route.push(1);

  cout << route.size() << '\n';

  while (!route.empty()) {
    cout << route.top() << ' ';
    route.pop();
  }
}
