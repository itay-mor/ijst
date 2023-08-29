#include <iostream>

using namespace std;

string run_print(char c, int n) {
  string s;
  for (int i = 0; i < n; i++) {
    s += c;
  }
  return s;
}

int main() {
  char c;
  int n;
  cin >> c >> n;

  cout << run_print(c, n);
  
}