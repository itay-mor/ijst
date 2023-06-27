#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

using namespace std;

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


/*-------------------------------------------- Question 1 --------------------------------------------*/


/**
 * Time complexity: O(n*log(n))
 * Memory complexity: O(n)
*/

int64_t solve_q1(vector<int64_t>& weights, int64_t max_weight) {
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


/*-------------------------------------------- Question 2 --------------------------------------------*/

/**
 * Time complexity: O(n^2)
 * Memory complexity: O(n)
*/

int64_t solve_q2() {
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

/*-------------------------------------------- Question 3 --------------------------------------------*/

/**
 * Time complexity: O(n*log(n))
 * Memory complexity: O(n)
*/

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


int64_t solve_q3(vector<project>& projects) {
  vector<int64_t> dp(projects.size(), -1);
  dp.push_back(0);

  sort(projects.begin(), projects.end());

  for (int64_t i = projects.size() - 1; i >= 0; i--) {
    auto [start_day, end_day, reward] = projects[i];
    auto next_available_project_index = lower_bound(projects.begin()+i, projects.end(), make_tuple(end_day+1, 0, 0)) - projects.begin();
    dp[i] = max(reward + dp[next_available_project_index], dp[i+1]);
  }

  return dp[0];
}
/*------------------------------------------- Run functions ------------------------------------------*/
void run_q1() {
  int64_t n, max_weight; cin >> n >> max_weight;
  auto weights = read_vector(n);

  cout << solve_q1(weights, max_weight) << endl << endl;
}

void run_q2() {
  cout << solve_q2() << endl << endl;
}

void run_q3() {
  auto projects = read_projects();
  cout << solve_q3(projects) << endl << endl;
}

/*----------------------------------------------- Main -----------------------------------------------*/

int main() {
  run_q1();
  run_q2();
  run_q3();
}
