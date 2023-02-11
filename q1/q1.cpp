#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

constexpr int kNotFound = -1000 * 1000 * 1000;  // Smallest possible value.

int find_second_biggest(const vector<int>& numbers) {
  /*
  Gets a vector.
  Returns the second biggest number.
  */

  int curr_biggest =
      kNotFound;  // setting the current biggest to the smallest possible value.
  int prev_biggest = kNotFound;  // setting the previous biggest to the
                                 // smallest possible value.
  for (int num : numbers) {
    if (num >= curr_biggest) {
      prev_biggest = curr_biggest;
      curr_biggest = num;
    } else if (num >= prev_biggest) {
      prev_biggest = num;
    }
  }
  return prev_biggest;
}

void expect_result(const vector<int>& numbers, int expected) {
  int actual = find_second_biggest(numbers);
  assert(actual == expected);
}

void run_tests() {
  /*
  Testing function.
  */
  expect_result({1, 2, 3, 4}, 3);
  expect_result({}, kNotFound);
  expect_result({7, 7, 7}, 7);
  expect_result({7}, kNotFound);
  expect_result({-1, -2, -3, -4}, -2);
  expect_result({-1000000, -2000000, -3000000, -4000000}, -2000000);
  expect_result({17, -2000000, 50, 5000799}, 50);
  expect_result({5000799, 17, -2000000, 50, 5000799}, 5000799);
}

int main() {
  // run_tests();

  int n;
  cin >> n;             // Getting a number and saving it in n.
  vector<int> numbers;  // Creating an array in size n.

  string line;
  getline(cin >> ws, line);
  stringstream ss(line);
  int number;

  while (ss >> number) {
    numbers.push_back(number);
  }

  assert(numbers.size() == n);

  cout << endl << find_second_biggest(numbers) << endl;
}