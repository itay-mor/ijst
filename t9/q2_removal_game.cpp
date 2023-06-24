// Time complexity: O(n^2)
// Storge complexity O(n)

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

vector<int64_t> read_vector(int size) {
  /**
   * Gets a size.
   * Return a vector from the user's input
  */
  
  vector<int64_t> vec;
  vec.reserve(size);

  int64_t temp;
  for (int i = 0; i < size; i++)
  {
    cin >> temp;
    vec.push_back(temp);
  }
  
  return vec;
}

int64_t run() {
  int n; cin >> n;
  auto numbers = read_vector(n);

  vector<int64_t> calculating_vector = (n%2 == 0) ? vector<int64_t>(n, 0) : numbers;
  
  for (int row = 1; row < n; row++) {
    for (int i = 0; i < n-row; i++) {
      if ((n-row)%2 == 1) {
        calculating_vector[i] = max(calculating_vector[i]+numbers[i+row], calculating_vector[i+1]+numbers[i]);
      } else {
        calculating_vector[i] = min(calculating_vector[i], calculating_vector[i+1]);
      }
      
    }
  }
  


  return calculating_vector[0];
}

int main() {
  cout << run() << endl;
}