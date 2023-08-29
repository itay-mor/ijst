#include <iostream>
using namespace std;

void run_q3() {
  string input;
  bool end = false;
  int max = 1000 * 1000 * 1000, min = -max, guess, turns = 1;

  while (true) {
    guess = (min + max) / 2;
    cout << guess << endl << ">> ";
    getline(cin, input);
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

int main() {
  run_q3();
  return 0;
}
