//
// Created by Itay Mor on 05/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

struct Dsu {
 public:
  vector<int> parent;
  vector<int> size;
  int components;
  int maximal_components;

  Dsu(int n) {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; ++i) parent[i] = i;
    components = n;
    maximal_components = 1;
  }

  int find_set(int i) {
    int root = i;
    while (parent[root] != root) {
      root = parent[root];
    }

    parent[i] = root;
    return root;
  }

  bool find_route(int x, int y) {
    return find_set(x) == find_set(y);
  }

  void make_union(int x, int y) {
    int root_x = find_set(x), root_y = find_set(y);
    if (root_x == root_y) return;
    int root;
    if (size[root_x] < size[root_y]) {
      parent[root_x] = y;
      size[root_y] += size[root_x];
      root = root_y;
    } else {
      parent[root_y] = x;
      size[root_x] += size[root_y];
      root = root_x;
    }
    components--;
    if (size[root] > maximal_components)
      maximal_components = size[root];
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  Dsu dsu(n);
  int a, b;
  while (m--) {
    cin >> a >> b;
    a--; b--;
    dsu.make_union(a, b);

    cout << dsu.components << " " << dsu.maximal_components << "\n";
  }
}