//
// Created by Itay Mor on 23/11/2023.
//
#include <bits/stdc++.h>

using namespace std;

using costumer = tuple<int, int, int>;

vector<costumer> read_vector(size_t size) {
  vector<costumer> vec(size);
  int a, b;
  for (int i = 0; i < size; ++i) {
    cin >> a >> b;
    vec[i] = make_tuple(a, b, i);
  }
  return vec;
}

pair<vector<int>, int> room_alocation(const vector<costumer>& costumers) {
  int rooms_counter = 1;
  vector<int> room_alocation(costumers.size());
  for (int i = 0; i < costumers.size(); ++i) {
    const auto& [check_in, check_out, index] = costumers[i];
    auto lower = lower_bound(costumers.begin(), costumers.end(), check_in, [](costumer element, int value) {
      return get<1>(element) > value;
    });

    if (lower == costumers.end()) {
      room_alocation[index] = rooms_counter;
      rooms_counter++;
      continue;
    }
    int found_index = get<2>(*(lower));
    room_alocation[index] = room_alocation[found_index];
  }
  return {room_alocation, rooms_counter};
}

int main() {
  int n; cin >> n;
  auto costumers = read_vector(n);
  sort(costumers.begin(), costumers.end());
  auto alocation = room_alocation(costumers);
  cout << alocation.second - 1<< endl;
  for (auto a : alocation.first) cout << a << " ";
}