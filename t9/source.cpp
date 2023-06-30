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

/*---------------------------- Question 1 ----------------------------*/

/**
 * Time complexity: O(n*log(n))
 * Memory complexity: O(n)
 */

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

/*---------------------------- Question 2 ----------------------------*/

/**
 * Time complexity: O(n^2)
 * Memory complexity: O(n)
 */

int64_t solve_removal_game(const vector<int64_t>& numbers) {
  size_t n = numbers.size();
  vector<int64_t> calculating_vector =
      (n % 2 == 0) ? vector<int64_t>(n, 0) : numbers;

  for (int row = 1; row < n; row++) {
    const int row_length = n - row;
    for (int i = 0; i < row_length; i++) {
      if (row_length % 2 == 1) {
        // 1st player's turn: maximize his sum.
        calculating_vector[i] = max(numbers[i] + calculating_vector[i + 1],
                                    numbers[i + row] + calculating_vector[i]);
      } else {
        // 2nd player's turn: minimize 1st player's sum.
        calculating_vector[i] =
            min(calculating_vector[i], calculating_vector[i + 1]);
      }
    }
  }

  return calculating_vector[0];
}

void run_removal_game() {
  int n;
  cin >> n;
  auto numbers = read_vector(n);
  cout << solve_removal_game(numbers) << endl;
}

/*---------------------------- Question 3 ----------------------------*/

/**
 * Time complexity: O(n*log(n))
 * Memory complexity: O(n)
 */

// project := ( start day, end day, reward )
using project = tuple<int64_t, int64_t, int64_t>;

vector<project> read_projects(size_t size) {
  int64_t start_day, end_day, reward;
  vector<project> projects(size);
  for (int64_t i = 0; i < size; i++) {
    cin >> start_day >> end_day >> reward;
    projects[i] = make_tuple(start_day, end_day, reward);
  }

  return projects;
}

int64_t solve_projects(vector<project>& projects) {
  // Saving maximum reward from i-th project to the end.
  vector<int64_t> dp(projects.size() + 1, 0);

  sort(projects.begin(), projects.end());

  for (int64_t i = projects.size() - 1; i >= 0; i--) {
    auto [start_day, end_day, reward] = projects[i];
    // Finding the index of the first project which starts after the current
    // project ends. If none is found, we get the an index outside the vector.
    auto next_available_project_index =
        lower_bound(projects.begin() + i,  //
                    projects.end(),        //
                    make_tuple(end_day + 1, 0, 0)) -
        projects.begin();
    // The maximum from the current project onwards is the maximum between:
    //   1. accepting the project and the previously calculated reward for
    //      projects which starts afterwards, or
    //   2. skipping the project, and getting the previously calculated reward
    //      for the remaining projects.
    dp[i] = max(reward + dp[next_available_project_index], dp[i + 1]);
  }

  // The solution is the calculated reward for the 1st project onwards.
  return dp[0];
}

void run_projects() {
  int64_t n;
  cin >> n;
  auto projects = read_projects(n);
  cout << solve_projects(projects) << endl;
}

/*------------------------------- Main -------------------------------*/

int main() {
  run_ferris_wheel();
  run_removal_game();
  run_projects();
}
