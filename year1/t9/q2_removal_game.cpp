// https://cses.fi/problemset/task/1097

// Time complexity: O(n^2)
// Memory complexity: O(n)

#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

vector<int64_t> read_vector(size_t size) {
  vector<int64_t> vec;
  vec.reserve(size);

  int64_t temp;
  for (int i = 0; i < size; i++) {
    cin >> temp;
    vec.push_back(temp);
  }

  return vec;
}

int64_t solve_removal_game(const vector<int64_t>& numbers) {
  size_t n = numbers.size();
  vector<int64_t> calculating_vector =
      (n % 2 == 0) ? vector<int64_t>(n, 0) : numbers;

  for (int row = 1; row < n; row++) {
    const int row_length = n - row;
    for (int i = 0; i < row_length; i++) {
      if (row_length % 2 == 1) {
        // 1st player's turn: maximize his sum.
        calculating_vector[i] = max(numbers[i] + calculating_vector[i + 1],
                                    numbers[i + row] + calculating_vector[i]);
      } else {
        // 2nd player's turn: minimize 1st player's sum.
        calculating_vector[i] =
            min(calculating_vector[i], calculating_vector[i + 1]);
      }
    }
  }

  return calculating_vector[0];
}

void run_removal_game() {
  int n;
  cin >> n;
  auto numbers = read_vector(n);
  cout << solve_removal_game(numbers) << endl;
}

int main() { run_removal_game(); }