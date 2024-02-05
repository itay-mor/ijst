//
// Created by Itay Mor on 04/02/2024.
//
#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> tree;
vector<vector<int>> children;
vector<int> tests;

void rooting(int node = 0, int father = -1) {
  for (int nei : tree[node]) {
    if (nei == father) continue;
    children[node].push_back(nei);
    rooting(nei, node);
  }
}


int set_tests(int node = 0, int father = 0, int max_test = 0) {
  int test = 0, mt = max_test;
  for (int i = 0; i < children[node].size(); i++) {
    while (tests[node] == test || tests[father] == test) {
      test++;
    }
    tests[children[node][i]] = test;
    mt = max(test, mt);
    test++;
  }
  int ans = mt;
  for (auto child : children[node]) {
    ans = max(set_tests(child, node, mt), ans);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  tree.resize(n);
  tests.resize(n);
  children.resize(n);
  int a, b;
  for (int i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    a--, b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  rooting();
  tests[0] = 0;
  cout << set_tests() + 1;
}