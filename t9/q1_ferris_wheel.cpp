// https://cses.fi/problemset/task/1090

// Time complexity: O(n*log(n))
// Memory complexity: O(n)

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

// Reads a vector from input.
// Gets the vector size and returns the vector.
vector<int64_t> read_vector(size_t size) {
  vector<int64_t> vec;
  vec.reserve(size);

  int64_t temp;
  for (int64_t i = 0; i < size; i++) {
    cin >> temp;
    vec.push_back(temp);
  }

  return vec;
}

// Gets the vector of the children's weights and the maximum weight of the
// gondolas. Returns the minimal amount of gondolas needed for all the children.
int64_t solve_ferris_wheel(vector<int64_t>& weights, int64_t max_weight) {
  int64_t min_gondolas = 0, left = 0, right = weights.size() - 1;

  sort(weights.begin(), weights.end());

  while ((right - left + 1) > 1) {
    if ((weights[left] + weights[right]) <= max_weight) {
      // We can add the lightest remaining child to gondola with the heaviest
      // one.
      left++;
    }

    // Put the heaviest child on the gondola.
    right--;

    min_gondolas++;
  }

  // Add the last remaining child (if any).
  min_gondolas += (right - left + 1);

  return min_gondolas;
}

void run_ferris_wheel() {
  int64_t n, max_weight;
  cin >> n >> max_weight;
  auto weights = read_vector(n);

  cout << solve_ferris_wheel(weights, max_weight) << endl;
}

int main() { run_ferris_wheel(); }