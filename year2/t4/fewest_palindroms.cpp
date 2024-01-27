//
// Created by Itay Mor on 28/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

int fewest_palindromes(const string& str) {
  vector<vector<bool>> is_palindrome(str.size(), vector<bool>(str.size()));
  for (int palindrome_end = 0; palindrome_end < str.size(); ++palindrome_end) {
    for (int palindrome_start = 0; palindrome_start <= palindrome_end; ++palindrome_start) {
      int length = palindrome_end - palindrome_start + 1;
      if (str[palindrome_start] != str[palindrome_end]) continue;

      if (length <= 3) is_palindrome[palindrome_start][palindrome_end] = true;
      else
        is_palindrome[palindrome_start][palindrome_end] = is_palindrome[palindrome_start + 1][palindrome_end - 1];

    }
  }

  vector<vector<int>> palindromes(str.length());
  int palindrome_start;
  for (int palindrome_end = 0; palindrome_end < str.size(); ++palindrome_end) {
    for (int palindrome_length = 1; palindrome_length <= palindrome_end + 1; ++palindrome_length) {
      palindrome_start = palindrome_end - palindrome_length + 1;
      if (is_palindrome[palindrome_start][palindrome_end]) palindromes[palindrome_end].push_back(palindrome_length);
    }
  }


  vector<int> dp(str.size() + 1, 1);
  dp[0] = 0;
  for (int i = 1; i <= str.length(); ++i) {
    dp[i] = dp[i - 1] + 1;
    for (int length : palindromes[i - 1])
      dp[i] = min(dp[i], dp[i - length] + 1);
  }

  return dp[str.size()];
}

int main() {
  cout << fewest_palindromes("abababab");
}