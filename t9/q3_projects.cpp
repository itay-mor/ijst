// Time complexity: O(n*log(n))
// Memory complexity: O(n)

#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

using project = tuple<int64_t, int64_t, int64_t>;

vector<project> read_projects() {
  int64_t n; cin >> n;
  project temp;
  int64_t start_day, end_day, reward;
  vector<project> projects(n);
  for (int64_t i = 0; i < n; i++) {
    cin >> start_day >> end_day >> reward;
    projects[i] = make_tuple(start_day, end_day, reward);
  }

  return projects;
}

int64_t run(vector<project>& projects) {
  vector<int64_t> dp(projects.size());

  sort(projects.begin(), projects.end());

  for (int64_t i = projects.size() - 1; i >= 0; i--) {
    auto [start_day, end_day, reward] = projects[i];
    auto next_available_project_index = lower_bound(projects.begin()+i, projects.end(), make_tuple(end_day+1, 0, 0)) - projects.begin();
    dp[i] = max(reward + dp[next_available_project_index], dp[i+1]);
  }

  return dp[0];
}

int main() {
  auto projects = read_projects();
  cout << run(projects) << endl;
}