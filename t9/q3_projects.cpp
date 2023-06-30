// https://cses.fi/problemset/task/1140

// Time complexity: O(n*log(n))
// Memory complexity: O(n)

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

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

int main() { run_projects(); }