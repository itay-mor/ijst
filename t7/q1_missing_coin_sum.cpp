// https://cses.fi/problemset/task/2183

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

vector<int64_t> read_sequence() {
  int64_t size;
  cin >> size;

  int64_t number;
  vector<int64_t> sequence;
  sequence.reserve(size);
  for (int64_t i = 0; i < size; i++) {
    cin >> number;
    sequence.push_back(number);
  }

  return sequence;
}

int64_t run() {
  vector<int64_t> coins = read_sequence();

  sort(coins.begin(), coins.end());

  int64_t next_coin_sum = 1;
  for (int64_t coin : coins) {
    if (coin > next_coin_sum) {
      // Our next coin is larger than the next sum we're trying to find.
      // It means we won't be able to find a set of coins that will have this sum, so we break.
      break;
    }
    // We found a coin that is smaller or equal to the sum we're looking for. It means
    // we could also add this coin, and look for a larger sum.
    next_coin_sum += coin;
  }
  
  return next_coin_sum;
}

int main() {
  cout << run() << endl;
  return 0;
}