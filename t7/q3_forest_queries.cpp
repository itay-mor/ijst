#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  int q;
  cin >> q;

  // Creating a (n+1)x(n+1) matrix of numbers that each one will
  // represent the number of trees in his right down.
  // All the numbers are initialised to be 0.
  vector<vector<int>> down_right_trees(n + 1, vector<int>(n + 1));
  vector<vector<char>> forest(n, vector<char>(n));

  string row;
  for (int y = 0; y < n; y++) {
    cin >> row;
    for (int x = 0; x < n; x++) {
      forest[y][x] = row[x];
    }
  }

  for (int y = n - 1; y >= 0; y--) {
    for (int x = n - 1; x >= 0; x--) {
      down_right_trees[y][x] = ((forest[y][x] == '*') ? 1 : 0)  //
                               + down_right_trees[y + 1][x]     //
                               + down_right_trees[y][x + 1]     //
                               - down_right_trees[y + 1][x + 1];
    }
  }

  string to_print = "";
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    int answer = down_right_trees[y1 - 1][x1 - 1]  //
                 - down_right_trees[y2][x1 - 1]    //
                 - down_right_trees[y1 - 1][x2]    //
                 + down_right_trees[y2][x2];
    to_print += to_string(answer) + "\n";
  }

  cout << to_print;

  return 0;
}
