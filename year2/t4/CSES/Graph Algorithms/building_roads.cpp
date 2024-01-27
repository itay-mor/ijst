//
// Created by Itay Mor on 23/12/2023.
//
#include <bits/stdc++.h>
#define CHOOSE2(n) n*(n-1)/2
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int n, m;

void mark_regin(int city) {
  if (visited[city]) return;

  visited[city] = true;
  for (auto node : graph[city]) {
    if (!visited[node]) mark_regin(node);
  }
}

int main() {
  cin >> n >> m;
  visited = vector<bool>(n+1);
  graph = vector<vector<int>>(n+1);
  int city1, city2;
  for (int i = 0; i < m; ++i) {
    cin >> city1 >> city2;
    graph[city1].push_back(city2);
    graph[city2].push_back(city1);
  }

  vector<int> unconnected_cities;
  for (int city = 1; city <= n; ++city) {
    if (!visited[city]) {
      mark_regin(city);
      unconnected_cities.push_back(city);
    }
  }
  cout << unconnected_cities.size() - 1 << "\n";
  for (int i = 0; i < unconnected_cities.size() - 1; ++i)
    cout << unconnected_cities[i] << ' ' << unconnected_cities[i + 1] << '\n';

}