// Time complexity: O(n*log(n))
// Memory complexity: O(n)

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

// Reads a vector from input.
// Gets the vector size and returns the vector.
vector<int64_t> read_vector(int64_t size) {
  vector<int64_t> vec;
  vec.reserve(size);

  int64_t temp;
  for (int64_t i = 0; i < size; i++)
  {
    cin >> temp;
    vec.push_back(temp);
  }
  
  return vec;
}


// Gets the vector of the children's weights, the maximum weight of the gondolas.
// Returns the minmal amount of gondolas needed for all the children.
int64_t run(vector<int64_t>& weights, int64_t max_weight) {
  int64_t min_gondolas = 0, left = 0, right = weights.size()-1;
  
  sort(weights.begin(), weights.end());
  while ((right-left+1) > 1) {
    if ((weights[left] + weights[right]) <= max_weight) {
      left++;
    }
    right--;
    min_gondolas++;
  }
  min_gondolas += (right-left+1);
  return min_gondolas;
}

int main() {
  int64_t n, max_weight; cin >> n >> max_weight;
  auto weights = read_vector(n);

  cout << run(weights, max_weight) << endl;
}