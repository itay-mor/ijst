//
// Created by Itay Mor on 26/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

void traffic_lights() {
  string ans = "";
  int length, lights; cin >> length >> lights;
  set<int> positions = {0, length};
  multiset<int> passages = {length};
  int light, prev_light, next_light;
  auto it1 = positions.begin(), it2 = positions.begin();
  auto max_passage = passages.begin();
  for (int i = 0; i < lights; ++i) {
    cin >> light;
    it1 = positions.upper_bound(light), it2 = positions.upper_bound(light);
    it1--;
    positions.insert(light);

    prev_light = *it1, next_light = *it2;

    passages.erase(passages.find(next_light-prev_light));
    passages.insert(light - prev_light);
    passages.insert(next_light - light);

    max_passage = passages.end(); max_passage--;
    ans += to_string(*max_passage);
    ans += " ";
  }

  cout << ans;
}

int main() {
  traffic_lights();
}