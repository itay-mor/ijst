//
// Created by Itay Mor on 24/09/2023.
// https://cses.fi/problemset/task/1091
//

#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_prices(size_t size) {
  vector<int64_t> return_vec(size);
  int64_t temp;
  for (size_t i = 0; i < size; i++) {
    cin >> temp;
    return_vec[i] = temp;
  }

  return return_vec;
}

multiset<int64_t> read_tickets(size_t size) {
  multiset<int64_t> return_multiset;
  int64_t temp;
  for (size_t i = 0; i < size; i++) {
    cin >> temp;
    return_multiset.insert(temp);
  }

  return return_multiset;
}

void run_concert_tickets() {
  int64_t tickets_num, costumers_num;
  cin >> tickets_num >> costumers_num;

  auto tickets = read_tickets(tickets_num);
  auto max_prices = read_prices(costumers_num);

  for (auto price : max_prices) {
    auto it = tickets.upper_bound(price);
    if (it == tickets.begin()) {
      cout << -1 << endl;
      continue;
    }
    it--;
    cout << *it << endl;
    tickets.erase(it);
  }

}

int main() {
  run_concert_tickets();
}