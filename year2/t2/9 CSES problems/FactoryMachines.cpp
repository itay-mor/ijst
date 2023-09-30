//
// Created by Itay Mor on 29/09/2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> return_vec(size);
  for (size_t i = 0; i < size; i++) cin >> return_vec[i];

  return return_vec;
}

int64_t products_at_time(int64_t time, const vector<int64_t>& machines) {
  int64_t products_num = 0;
  for (auto machine : machines) {
    products_num += (time / machine);
  }
  return products_num;
}

void run_factory_machine() {
  int n, products_num;
  cin >> n >> products_num;

  auto machines = read_vector(n);
  int64_t max_time = (*min_element(machines.begin(), machines.end())) * products_num;
  int64_t min_time = 0;
  int64_t guessed_time = (max_time + min_time) / 2;
  int64_t exact_time = max_time;
  while (min_time < max_time) {
    auto p = products_at_time(guessed_time, machines);
    if (products_num <= p && guessed_time < exact_time) exact_time = guessed_time;

    if (p < products_num) min_time = guessed_time + 1;
    else max_time = guessed_time - 1;

    guessed_time = (max_time + min_time) / 2;
  }
  auto p = products_at_time(guessed_time, machines);
  if (products_num <= p && guessed_time < exact_time) exact_time = guessed_time;

  cout << exact_time;
}

int main() {
  run_factory_machine();
}