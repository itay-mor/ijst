#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

constexpr int kNotFound = -1000 * 1000 * 1000; // Smallest posible value.

int find_second_biggest(const int arr[], int arr_length) {
  /*
  Gets an array and the length of it.
  Returns the second biggest number.
  */
 
  int curr_biggest =
      kNotFound;  // setting the current biggest to the smallest possible value.
  int prev_biggest = kNotFound;  // setting the previous biggest to the
                                 // smallest possible value.
  for (int i = 0; i < arr_length; i++) {
    if (arr[i] >= curr_biggest) {
      prev_biggest = curr_biggest;
      curr_biggest = arr[i];
    } else if (arr[i] >= prev_biggest) {
      prev_biggest = arr[i];
    }
  }
  return prev_biggest;
}

int find_second_biggest2(const vector<int> arr, int arr_length) {
  /*
  Gets an array and the length of it.
  Returns the second biggest number.
  */
 
  int curr_biggest =
      kNotFound;  // setting the current biggest to the smallest possible value.
  int prev_biggest = kNotFound;  // setting the previous biggest to the
                                 // smallest possible value.
  for (int i = 0; i < arr_length; i++) {
    if (arr[i] >= curr_biggest) {
      prev_biggest = curr_biggest;
      curr_biggest = arr[i];
    } else if (arr[i] >= prev_biggest) {
      prev_biggest = arr[i];
    }
  }
  return prev_biggest;
}


void expect_result(const vector<int> &numbers, int expected) {
  int actual = find_second_biggest(numbers.data(), numbers.size());
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
  string temp;
  cin >> n;    // Geting a number and sving it in n.
  vector<int> arr;  // Creating an array in size n.
  while (std::getline(cin, temp, ' ')) {
    arr.push_back(stoi(temp));
  }


  cout << endl << find_second_biggest2(arr, n) << endl;
}