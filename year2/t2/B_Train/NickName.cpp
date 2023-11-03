//
// Created by Itay Mor on 07/10/2023.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

void run_nick_name() {
  int n; cin >> n;
  string name;
  cin >> name;

  set<string> found_names;
  for (int i = 0; i < n-1; ++i) {
    for (int j = i+1; j < n; ++j) {
      string new_string;
      for (int k = 0; k < n; ++k) {
        if (k == i || k == j) continue;
        new_string += name[k];
      }
      found_names.emplace(new_string);
    }
  }
  cout << found_names.size();
}

int main() {
  run_nick_name();
}