//
// Created by Itay Mor on 21/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> children;
vector<vector<int>> tree;
vector<int> depth;

void rooting(int node = 0, int father = -1) {
  for (int nei : tree[node]) {
    if (nei == father) continue;
    children[node].push_back(nei);
    rooting(nei, node);
  }
}

int find_deepest(int node = 0) {
  if (children[node].empty()) return depth[node] = 0;
  int max_depth = 0;
  for (auto child : children[node]) {
    if (depth[child] != -1) max_depth = max(max_depth, depth[child] + 1);
    else max_depth = max(max_depth, find_deepest(child) + 1);
  }
  return depth[node] = max_depth;
}

int find_diameter(int node = 0) {
  if (children[node].empty()) return 0;
  int ans = 0;
  for (auto child : children[node])
    ans = max(ans, find_diameter(child));

  int max_depth1 = 0, max_depth2 = 0;
  for (auto child : children[node]) {
    if (depth[child] + 1 > max_depth1) {
      max_depth2 = max_depth1;
      max_depth1 = depth[child] + 1;
    } else if (depth[child] + 1 > max_depth2) {
      max_depth2 = depth[child] + 1;
    }
  }

  ans = max(ans, max_depth1 + max_depth2);
  return ans;
}

int main() {
  int n;
  cin >> n;
  tree.resize(n);
  children.resize(n);
  depth.assign(n, -1);

  int temp1, temp2;
  n--;
  while (n--) {
    cin >> temp1 >> temp2;
    tree[temp1 - 1].push_back(temp2 - 1);
    tree[temp2 - 1].push_back(temp1 - 1);
  }
  rooting();
  find_deepest();
  cout << find_diameter();
}