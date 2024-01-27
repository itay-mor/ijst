//
// Created by Itay Mor on 14/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int dist(string str_1, string str_2) {
  vector<vector<int>> dp(str_1.length()+1, vector<int>(str_2.length() + 1, 0));
  for (auto& row : dp)


  for (int i = 1; i < str_1.length()+1; ++i)
    for (int j = 1; j < str_2.length()+1; ++j)
      dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (str_1[i-1] != str_2[j-1])});



  return dp[str_1.length()][str_2.length()];
}

int main() {
  string string_1, string_2;
  cin >> string_1 >> string_2;
  cout << dist(string_1, string_2);
}