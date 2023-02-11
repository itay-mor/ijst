#include <iostream>
using namespace std;

void game() {
  string input;
  bool end = false;
  int max = 1000 * 1000 * 1000, min = -max, guess, turns = 1;

  while (true) {
    guess = (min + max) / 2;
    cout << guess << endl << ">> ";
    cin >> input;
    if (input == "up") {
      min = guess + 1;
      turns++;
    } else if (input == "down") {
      max = guess - 1;
      turns++;
    } else if (input == "got") {
      cout << "Secseeded in " << turns << " turns." << endl;
      return;
    }
  }
}

int main() {
  game();
  return 0;
}
