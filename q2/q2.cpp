#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

constexpr int kDistFromPrivet = 777;
constexpr int kDistFromLondon = 500;
constexpr int kHagridMultiplier = 3;

double opTimeOfDurr(double speed, bool monday, bool hagrid) {
  /*
   * Gets the mop speed, a boolian variable which is true if it's monday and a
   * boolian variable which is true if hagrid came.
   * Returns the minimal time to howarts.
   */

  double actual_speed = speed;
  double distance = kDistFromPrivet;
  /* When hagrid comes it's always better to go with him, even if it's monday
   * because when it's monday and also hargid came - with hagrid the time is
   * 259/speed and from london the time is 500/speed wich is allways bigger. So
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

void expect_result(double speed, bool monday, bool hagrid, double expected) {
  /*
   * Geting the paramiters of opTimeOfDurr func and the expected result and
   * asserting an eror if the fuction returned unexpected value.
   */
  double actual = opTimeOfDurr(speed, monday, hagrid);
  assert(actual == expected);
}

void run_tests() {
  /*
   * Testing function.
   */
  expect_result(1, false, false, 777.00);
  expect_result(1, true, false, 500.00);
  expect_result(1, false, true, 259.00);
  expect_result(1, true, true, 259.00);
  expect_result(100, true, false, 5.00);
  expect_result(777 * 3600 / 30.0, false, false, 0.00);
  expect_result(777 * 3600 / 31.0, false, false, 0.01);
}

int main() {
  // run_tests();

  double speed;
  string day;
  string hagrid;
  cin >> speed >> day >> hagrid;
  cout << opTimeOfDurr(speed, (day == "monday"), (hagrid == "yes")) << endl;
}