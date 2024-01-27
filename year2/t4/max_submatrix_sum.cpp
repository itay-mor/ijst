//
// Created by Itay Mor on 26/12/2023.
//
#include <bits/stdc++.h>

using namespace std;
using matrix = vector<vector<int>>;


int max_submatrix_sum(const matrix& A) {
  auto n = A.size();
  matrix partial_sums(n + 1, vector<int>(n, 0));
  for (int j = 0; j < n; ++j) {
    for (int i = 1; i <= n; ++i)
      partial_sums[i][j] = partial_sums[i - 1][j] + A[i - 1][j];
  }
  int max_sum, curr_max, col_sum, ans = numeric_limits<int>::min();
  for (int row1 = 0; row1 < n; ++row1) {
    for (int row2 = row1; row2 < n; ++row2) {
      curr_max = 0;
      max_sum = numeric_limits<int>::min();
      for (int col = 0; col < n; ++col) {
        col_sum = partial_sums[row2 + 1][col] - partial_sums[row1][col];
        curr_max += col_sum;
        max_sum = max(max_sum, curr_max);

        if (curr_max < col_sum) curr_max = col_sum;
      }
    }
    ans = max(ans, curr_max);
  }
  return ans;
}

int main() {
  cout << max_submatrix_sum({
                                {-17, -17},
                                {16, -17}

  });
}