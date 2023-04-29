// https://cses.fi/problemset/task/1145

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

int64_t find_longest_increasing_subsequence(const vector<int64_t>& sequence) {
  vector<int64_t> vec;
  for (int64_t number : sequence) {
    // Binary search for first element that is equal or greater than number.
    auto it = lower_bound(vec.begin(), vec.end(), number);
    if (it == vec.end()) {
      // Larger than the tail (or first number); start a new column with it.
      vec.push_back(number);
    } else {
      // Replace the element with our number.
      *it = number;
    }
  }
  return vec.size();
}

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
  vector<int64_t> sequence = read_sequence();
  return find_longest_increasing_subsequence(sequence);
}

int main() {
  cout << run() << endl;
  return 0;
}