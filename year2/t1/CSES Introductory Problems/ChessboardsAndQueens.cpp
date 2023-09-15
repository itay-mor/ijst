//
// Created by Itay Mor on 11/09/2023.
//

#include <bits/stdc++.h>

using namespace std;

constexpr int CHESSBOARD_SIZE = 8;
constexpr int QUEENS_NUMBER = 8;

using Chessboard = array<string, CHESSBOARD_SIZE>;

Chessboard read_chessboard() {
  Chessboard chessboard;
  for (int i = 0; i < CHESSBOARD_SIZE; ++i) {
    string row;
    cin >> row;

    chessboard[i] = row;
  }
  return chessboard;
}

Chessboard mark_attacked_squares(tuple<int, int> queen, Chessboard chessboard) {
  auto [queen_x, queen_y] = queen;

  // Marking the queen's column.
  for (int y = 0; y < CHESSBOARD_SIZE; ++y) chessboard[y][queen_x] = '*';

  // Marking the queen's row.
  for (int x = 0; x < CHESSBOARD_SIZE; ++x) chessboard[queen_y][x] = '*';

  // Marking the queen's diagonals.
  for (int y = 0, x = queen_x - queen_y; y < CHESSBOARD_SIZE; ++y, ++x) {
    if (0 <= x && x < CHESSBOARD_SIZE) chessboard[y][x] = '*';
  }
  for (int y = 0, x = queen_x + queen_y; y < CHESSBOARD_SIZE; ++y, --x) {
    if (0 <= x && x < CHESSBOARD_SIZE) chessboard[y][x] = '*';
  }

  return chessboard;
}

int64_t number_of_solutions(Chessboard chessboard,
                            int queens_num = QUEENS_NUMBER,
                            tuple<int, int> last_queen = {0, 0}) {
  if (queens_num == 0) return 1;

  int64_t num_of_solutions = 0;
  auto [last_queen_x, last_queen_y] = last_queen;

  for (int y = last_queen_y; y < CHESSBOARD_SIZE; ++y) {
    for (int x = 0; x < CHESSBOARD_SIZE; ++x) {

      if (chessboard[y][x] == '*') continue;

      if (y == last_queen_y && x < last_queen_x) continue;

      Chessboard new_chessboard = mark_attacked_squares({x, y}, chessboard);
      num_of_solutions +=
          number_of_solutions(new_chessboard, queens_num - 1, {x, y});
    }
  }

  return num_of_solutions;
}

int main() {
  Chessboard chessboard = read_chessboard();

  cout << number_of_solutions(chessboard);
}