#include <iostream>

using namespace std;


int main() {
  long long n; cin >> n;

  long long curr_num=0, prev_num=0, moves=0, add = 0;
  for (long i = 0; i < n; i++)
  {
    prev_num = curr_num+add;
    cin >> curr_num;
    add = 0;
    
    if (curr_num<prev_num) 
    {
      add = prev_num-curr_num;
      moves += add;
    }
  }
  cout << moves << endl;
  
}