//
// Created by Itay Mor on 23/12/2023.
//

#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> arrived_from;
vector<string> grid;
int n, m;

struct coord {
  int x, y;
  coord(int x, int y) : x(x), y(y) {}
  coord() : coord(0, 0) {}

  void operator+=(coord c) {
    x += c.x;
    y += c.y;
  }

  bool operator==(coord c) const {
    return x == c.x && y == c.y;
  }

  bool operator!=(coord c) const {
    return !(c == *this);
  }

  coord right() const {
    return coord(x + 1, y);
  }

  coord left() const {
    return coord(x - 1, y);
  }

  coord up() const {
    return coord(x, y - 1);
  }

  coord down() const {
    return coord(x, y + 1);
  }
};

map<char, coord> directions = {
    {'R', {-1, 0}},
    {'L', {1, 0}},
    {'D', {0, -1}},
    {'U', {0, 1}},
};

inline bool is_floor(coord c) {
  return (c.x >= 0) && (c.y >= 0) && (c.x < m) && (c.y < n) && grid[c.y][c.x] != '#';
}

void bfs(coord a, coord b) {
  queue<coord> bfs;

  bfs.push(a);
  vector<pair<coord, char>> attempts;
  while (!bfs.empty()) {
    coord curr = bfs.front();
    bfs.pop();

    attempts = {
        {curr.right(), 'R'},
        {curr.left(), 'L'},
        {curr.up(), 'U'},
        {curr.down(), 'D'},
    };

    for (auto [next, symbol] : attempts) {
      if (is_floor(next) && arrived_from[next.y][next.x] == '?') {
        arrived_from[next.y][next.x] = symbol;
        if (next == b) return;
        bfs.push(next);
      }
    }
  }
}

void labyrinth() {
  coord a{0, 0}, b{0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'A')
        a = {j, i};

      if (grid[i][j] == 'B')
        b = {j, i};
    }
  }

  bfs(a, b);

  if (arrived_from[b.y][b.x] == '?') {
    cout << "NO";
    return;
  }

  string ans = "";
  while (b != a) {
    auto direction = arrived_from[b.y][b.x];
    ans += direction;
    b += directions[direction];
  }

  reverse(ans.begin(), ans.end());

  cout << "YES\n" << ans.length() << "\n" << ans;

}

int main() {
//  ifstream cin("C:\\Users\\Itay Mor\\CLionProjects\\ijst\\year2\\t4\\CSES\\Graph Algorithms\\test_13.txt");
  cin >> n >> m;
  grid = vector<string>(n);
  arrived_from = vector<vector<char>>(n, vector<char>(m, '?'));

  for (auto& row : grid)
    cin >> row;

  labyrinth();
}