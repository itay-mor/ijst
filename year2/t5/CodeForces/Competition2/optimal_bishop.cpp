//
// Created by Itay Mor on 27/01/2024.
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//
//int bishop_sum(const vector<vector<int>>& board, int n, int m) {
//  vector<vector<int>> ur, ul, dr, dl;
//
//  ur.assign(n, vector<int>(m, 0));
//  ul.assign(n, vector<int>(m, 0));
//  dr.assign(n, vector<int>(m, 0));
//  dl.assign(n, vector<int>(m, 0));
//
//  for (int i = 1; i < n; ++i) {
//    for (int j = 1; j < m; ++j) {
//      ul[i][j] = ul[i - 1][j - 1] + board[i - 1][j - 1];
//      ur[i][n - j - 1] = ur[i - 1][n - j] + board[i - 1][n - j];
//      dr[n - i - 1][n - j - 1] = dr[n - i][n - j] + board[n - i][n - j];
//      dl[n - i - 1][j] = dl[n - i][j - 1] + board[n - i][j - 1];
//    }
//  }
//
//  int optimal_bishop = 0;
//  for (int i = 0; i < n; ++i) {
//    for (int j = 0; j < m; ++j) {
//      optimal_bishop = max(optimal_bishop,
//                           ul[i][j] + ur[i][j] + dl[i][j] + dr[i][j] + board[i][j]);
//    }
//  }
//  return optimal_bishop;
//}
//
//int main() {
//  int t; cin >> t;
//  int n, m;
//  vector<vector<int>> board;
//  while (t--) {
//    cin >> n >> m;
//    board.assign(n, vector<int>(m));
//    for (auto& row : board)
//      for (auto& col : row)
//        cin >> col;
//    cout << bishop_sum(board, n, m) << '\n';
//  }
//}
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int sum = 0;
      int ci = i, cj = j;
      while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
        sum += a[ci][cj];
        ci--;
        cj--;
      }
      ci = i, cj = j;
      while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
        sum += a[ci][cj];
        ci++;
        cj--;
      }
      ci = i, cj = j;
      while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
        sum += a[ci][cj];
        ci--;
        cj++;
      }
      ci = i, cj = j;
      while (ci >= 0 && ci < n && cj >= 0 && cj < m) {
        sum += a[ci][cj];
        ci++;
        cj++;
      }
      sum -= a[i][j] * 3;
      mx = max(mx, sum);
    }
  }
  cout << mx << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}