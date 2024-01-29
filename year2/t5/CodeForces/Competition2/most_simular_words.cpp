//
// Created by Itay Mor on 27/01/2024.
//
#include <bits/stdc++.h>

using namespace std;

int diff(const string& string_1, const string& string_2, int m) {
  int d = 0;
  for (int i = 0; i < m; ++i)
    d += abs(string_1[i] - string_2[i]);
  return d;
}

int main() {
  int t; cin >> t;
  int n, m, d;
  vector<string> words;
  while (t--) {
    cin >> n >> m;
    words.resize(n);
    d = numeric_limits<int>::max();
    for (auto& word : words)
      cin >> word;
    for (int i = 0; i < n - 1; ++i)
      for (int j = i + 1; j < n; ++j)
        d = min(diff(words[i], words[j], m), d);

    cout << d << '\n';
  }
}