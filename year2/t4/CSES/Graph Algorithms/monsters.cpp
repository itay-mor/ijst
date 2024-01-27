//
// Created by Itay Mor on 24/12/2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
vector<vector<int>> turn_arrived, monsters_turn_arrived;
int n, m;

struct coord {
 private:
  bool monster = false;

 public:

  int x, y;
  coord(int x, int y) : x(x), y(y) {}
  coord() : coord(0, 0) {}

  void operator+=(coord c) {
    x += c.x;
    y += c.y;
  }

  bool operator==(const coord& c) const {
    return x == c.x && y == c.y;
  }

  bool operator!=(const coord& c) const {
    return !(c == *this);
  }

  coord right() const {
    coord c(x + 1, y);
    if (monster) c.set_monster();
    return c;
  }

  coord left() const {
    coord c(x - 1, y);
    if (monster) c.set_monster();
    return c;
  }

  coord up() const {
    coord c(x, y - 1);
    if (monster) c.set_monster();
    return c;
  }

  coord down() const {
    coord c(x, y + 1);
    if (monster) c.set_monster();
    return c;
  }

  void set_monster() {
    monster = !monster;
  }

  bool is_monster() const {
    return monster;
  }
  bool is_border() {
    return (x == 0) || (y == 0) || (x == m - 1) || (y == n - 1);
  }

};

inline bool is_floor(coord c) {
  return (c.x >= 0) && (c.y >= 0) && (c.x < m) && (c.y < n) && grid[c.y][c.x] != '#';
}

coord bfs(const coord& a, const vector<coord>& monsters) {
  queue<coord> bfs;
  vector<coord> attempts;
  for (auto monster : monsters)
    bfs.push(monster);

  bfs.push(a);

  coord curr;
  while (!bfs.empty()) {
    curr = bfs.front();
    bfs.pop();

    attempts = {
        {curr.right()},
        {curr.left()},
        {curr.up()},
        {curr.down()},
    };

    for (auto attempt : attempts) {
      if (!is_floor(attempt)) continue;
      if (attempt.is_monster()) {
        if (monsters_turn_arrived[attempt.y][attempt.x] != -1) continue;
        monsters_turn_arrived[attempt.y][attempt.x] = monsters_turn_arrived[curr.y][curr.x] + 1;
      } else {
        if (monsters_turn_arrived[attempt.y][attempt.x] != -1) continue;
        if (turn_arrived[attempt.y][attempt.x] != -1) continue;
        turn_arrived[attempt.y][attempt.x] = turn_arrived[curr.y][curr.x] + 1;
        if (attempt.is_border()) return attempt;
      }
      bfs.push(attempt);
    }
  }
  return {-1, -1};
}
void monsters() {
  vector<coord> monsters;
  coord a;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'M') {
        monsters_turn_arrived[i][j] = 0;
        coord c(j, i);
        c.set_monster();
        monsters.push_back(c);
      }
      if (grid[i][j] == 'A') {
        turn_arrived[i][j] = 0;
        a = {j, i};
      }
    }
  }
  if (a.is_border()) {
    cout << "YES\n" << 0;
    return;
  }
  vector<pair<coord, char>> attempts;
  string ans;
  auto end_coord = bfs(a, monsters);
  if (end_coord == coord{-1, -1}) {
    cout << "NO";
    return;
  }
  while (end_coord != a) {
    attempts = {
        {end_coord.right(), 'L'},
        {end_coord.left(), 'R'},
        {end_coord.up(), 'D'},
        {end_coord.down(), 'U'},
    };
    for (auto& [attempt, symbol] : attempts) {
      if (!is_floor(attempt)) continue;
      if (turn_arrived[attempt.y][attempt.x] == turn_arrived[end_coord.y][end_coord.x] - 1) {
        end_coord = attempt;
        ans += symbol;
        break;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << "YES\n" << ans.length() << "\n" << ans;
}

int main() {
  cin >> n >> m;
  grid = vector<string>(n);
  for (auto& row : grid)
    cin >> row;

  turn_arrived = vector<vector<int>>(n, vector<int>(m, {-1}));
  monsters_turn_arrived = vector<vector<int>>(n, vector<int>(m, -1));
  monsters();
}