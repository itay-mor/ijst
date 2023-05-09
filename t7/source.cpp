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

/*-------------------------------------------- Question 1 --------------------------------------------*/

int64_t run_q1() {
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

/*-------------------------------------------- Question 2 --------------------------------------------*/

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

int64_t run_q2() {
  vector<int64_t> sequence = read_sequence();
  return find_longest_increasing_subsequence(sequence);
}

/*-------------------------------------------- Question 3 --------------------------------------------*/

string run_q3() {
  int n;
  cin >> n;
  int q;
  cin >> q;

  // Creating a (n+1)x(n+1) matrix of numbers that each one will
  // represent the number of trees in his right down.
  // All the numbers are initialised to be 0.
  vector<vector<int>> down_right_trees(n + 1, vector<int>(n + 1));
  vector<vector<char>> forest(n, vector<char>(n));

  string row;
  for (int y = 0; y < n; y++) {
    cin >> row;
    for (int x = 0; x < n; x++) {
      forest[y][x] = row[x];
    }
  }

  for (int y = n - 1; y >= 0; y--) {
    for (int x = n - 1; x >= 0; x--) {
      down_right_trees[y][x] = ((forest[y][x] == '*') ? 1 : 0)  //
                               + down_right_trees[y + 1][x]     //
                               + down_right_trees[y][x + 1]     //
                               - down_right_trees[y + 1][x + 1];
    }
  }

  string answers = "";
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    int answer = down_right_trees[y1 - 1][x1 - 1]  //
                 - down_right_trees[y2][x1 - 1]    //
                 - down_right_trees[y1 - 1][x2]    //
                 + down_right_trees[y2][x2];
    answers += to_string(answer) + "\n";
  }

  return answers;
}

/*----------------------------------------------- Main -----------------------------------------------*/

int main() {
  cout << run_q1() << endl << endl;
  cout << run_q2() << endl << endl;
  cout << run_q3() << endl << endl;
}