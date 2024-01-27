//
// Created by Itay Mor on 26/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int removals(const multiset<int>& problems, int k) {
  priority_queue<int> sequences;
  int length = 0, prev_problem = *problems.begin();
  for (int problem : problems) {
    if (abs(problem - prev_problem) > k)
      sequences.push(length), length = 1;
    else
      length++;
    prev_problem = problem;
  }
  sequences.push(length);
  return problems.size() - sequences.top();
}

int main() {
  int t; cin >> t;
  int n, k, problem;
  multiset<int> problems;
  while (t--) {
    problems.clear();
    cin >> n >> k;
    while (n--) {
      cin >> problem;
      problems.insert(problem);
    }
    cout << removals(problems, k) << '\n';
  }
}