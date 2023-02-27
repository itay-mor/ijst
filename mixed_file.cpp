#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*-------------------------------------------- Question 1 --------------------------------------------*/

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

void run_q1() {
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

/*-------------------------------------------- Question 2 --------------------------------------------*/

constexpr int kDistFromPrivet = 777;
constexpr int kDistFromLondon = 500;
constexpr int kHagridMultiplier = 3;

double opTimeOfDur(double speed, bool monday, bool hagrid) {
  /*
   * Gets the mop speed, a boolean variable which is true if it's monday and a
   * boolean variable which is true if hagrid came.
   * Returns the minimal time to howarts.
   */

  double actual_speed = speed;
  double distance = kDistFromPrivet;
  /* When hagrid comes it's always better to go with him, even if it's monday
   * because when it's monday and also hagrid came - with hagrid the time is
   * 259/speed and from london the time is 500/speed which is always bigger. So
   * first we check if hagrid came and only if he didn't we check if it's
   * monday.
   */
  if (hagrid) {
    actual_speed *= kHagridMultiplier;
  } else if (monday) {
    distance = kDistFromLondon;
  }
  double time = distance / actual_speed;

  // Calculating the hours, the minutes and the seconds.
  int hours = int(time);
  double minutes = (time - hours) * 60;
  double seconds = (minutes - int(minutes)) * 60;

  // Rounding minutes to the closest round minute (30 seconds is round down).
  minutes = (seconds > 30) ? int(minutes + 1) : int(minutes);

  return hours + minutes / 100.0;
}

void run_q2() {
  double speed;
  string day;
  string hagrid;
  cin >> speed >> day >> hagrid;
  cout << opTimeOfDur(speed, (day == "monday"), (hagrid == "yes")) << endl;
}

/*-------------------------------------------- Question 3 --------------------------------------------*/

void run_q3() {
  string input;
  bool end = false;
  int max = 1000 * 1000 * 1000, min = -max, guess, turns = 1;

  while (true) {
    guess = (min + max) / 2;
    cout << guess << endl << ">> ";
    getline(cin >> ws, input);
    if (input == "up") {
      min = guess + 1;
      turns++;
    } else if (input == "down") {
      max = guess - 1;
      turns++;
    } else if (input == "got it!") {
      cout << "Succeeded in " << turns << " turns." << endl;
      return;
    }
  }
}

/*-------------------------------------------- Main --------------------------------------------*/
int main() {
  cout << "Question 1:" << endl;
  run_q1();
  cout << "Question 2:" << endl;
  run_q2();
  cout << "Question 3:" << endl;
  run_q3();
}