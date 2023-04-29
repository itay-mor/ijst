#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;



int main() {
  int64_t temp;
  vector<int64_t> coins;
  int64_t n; cin >> n;
  for (int64_t i = 0; i < n; i++) {
    cin >> temp;
    coins.push_back(temp);
  }

  sort(coins.begin(), coins.end());


  int64_t max_following_sum = 0;
  int64_t i = 0;
  for (int64_t coin : coins) {
    if (coin > max_following_sum+1) {
      break;
    }
    max_following_sum += coin;
  }
  
  cout << max_following_sum+1 << endl;

}
