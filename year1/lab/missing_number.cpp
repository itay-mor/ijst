#include <iostream>

using namespace std;


int main() {
  long n;
  cin >> n;

  long sum = ((n+1)*(n))/2;
  
  long int temp;
  for (long i = 1; i < n; i++)
  {
    cin >> temp;
    sum -= temp;
  }

  cout << sum << endl;
  

  return 0;
}