#include "dbg.h"
#include <queue>
#include <vector>

void bfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int row,
         int col, bool capture) {
  int m = board.size(), n = board[0].size();
  int drow[4] = {1, -1, 0, 0};
  int dcol[4] = {0, 0, 1, -1};
  queue<pair<int, int>> q = {};
  visited[row][col] = true;
  q.push({row, col});

  while (!q.empty()) {
    pair<int, int> front = q.front();
    q.pop();

    int x, y;
    for (int i = 0; i < 4; i++) {
      x = front.first + drow[i];
      y = front.second + dcol[i];

      if (x >= 0 && x < m && y >= 0 && y < n && board[x][y] == 'O' &&
          !visited[x][y]) {
        visited[x][y] = true;
        q.push({x, y});
      }
    }
  }

  return;
}

void solve(vector<vector<char>> &board) {
  int m = board.size(), n = board[0].size();
  if (m <= 2 || n <= 2) {
    return;
  }
  vector<vector<bool>> visited(m, vector<bool>(n, false));

  // visit all the edge chars
  for (int row = 0; row < m; row += m - 1) {
    for (int col = 0; col < n; col++) {
      if (board[row][col] == 'O' && !visited[row][col]) {
        bfs(board, visited, row, col, false);
      }
    }
  }
  for (int col = 0; col < n; col += n - 1) {
    for (int row = 0; row < m; row++) {
      if (board[row][col] == 'O' && !visited[row][col]) {
        bfs(board, visited, row, col, false);
      }
    }
  }

  for (int row = 1; row < m - 1; row++) {
    for (int col = 1; col < n - 1; col++) {
      if (board[row][col] == 'O' && !visited[row][col]) {
        board[row][col] = 'X';
      }
    }
  }
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func
  vector<vector<char>> board = {{'X'}};
  board = {{'X', 'X', 'X', 'X'},
           {'X', 'O', 'O', 'X'},
           {'X', 'X', 'O', 'X'},
           {'X', 'O', 'X', 'X'}};
  solve(board);
  for (auto row : board)
    dbg_print_each(row);

  return EXIT_SUCCESS;
}
