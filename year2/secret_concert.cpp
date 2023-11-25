//
// Created by Itay Mor on 22/11/2023.
//

#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& tickets) {
  int groups_counter = 0;
  int group_modulu = 0;
  bool taken_last;
  for (auto t: tickets) {
    if (t%2 == group_modulu) {
      taken_last = true;
      groups_counter++;
    }
    else taken_last = false;
    group_modulu = (group_modulu + t)%2;

  }
  return groups_counter - !taken_last;
}

int main() {
  auto vec = {1, 2, 1 ,5, 6};
  cout << solve(vec);
}