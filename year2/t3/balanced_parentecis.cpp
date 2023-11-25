//
// Created by Itay Mor on 21/11/2023.
//
#include <bits/stdc++.h>
#define START_MARKER '.'
using namespace std;

bool is_balanced(const string& str) {
  static map<char, char> parens_pairs = {
      {')', '('},
      {']', '['},
      {'}', '{'},
      {'>', '<'},
  };
  stack<char> parens;
  parens.push(START_MARKER);
  for (auto c : str) {
    switch (c) {
      case '(':
      case '[':
      case '{':
      case '<':
        parens.push(c);
        break;

      case ')':
      case ']':
      case '}':
      case '>':
        if (parens.top() == parens_pairs[c]) parens.pop();
        else return false;
        break;

      default:
        continue;
    }
  }
  return true;
}

int main() {
  string string_1;
  cin >> string_1;

  cout << is_balanced(string_1);
}
