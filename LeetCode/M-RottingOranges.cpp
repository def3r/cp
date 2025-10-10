#include "dbg.h"
#include <climits>
#include <queue>
#include <vector>

int orangesRotting(vector<vector<int>> &grid) {
  int res = 0;
  int m = grid.size(), n = grid[0].size();
  int rot[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      rot[i][j] = INT_MAX;
    }
  }
  queue<pair<int, int>> q = {};

  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] != 2)
        continue;
      int time = 0;
      rot[row][col] = time;
      q.push({row, col});

      while (!q.empty()) {
        int q_size = q.size();
        time++;

        while (q_size--) {
          pair<int, int> front = q.front();
          q.pop();

          int x, y;
          x = front.first;
          for (int offset = -1; offset <= 1; offset += 2) {
            y = front.second + offset;
            if (y >= 0 && y < n && grid[x][y] == 1 && rot[x][y] > time) {
              rot[x][y] = time;
              q.push({x, y});
            }
          }

          y = front.second;
          for (int offset = -1; offset <= 1; offset += 2) {
            x = front.first + offset;
            if (x >= 0 && x < m && grid[x][y] == 1 && rot[x][y] > time) {
              rot[x][y] = time;
              q.push({x, y});
            }
          }
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      dbg_var_t(rot[i][j]);
    }
    dbg_nl();
  }
  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == 1) {
        if (rot[row][col] == INT_MAX)
          return -1;
        res = max(res, rot[row][col]);
      }
    }
  }

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun orangesRotting(grid);
  vector<vector<int>> grid;

  dbg_test_with(4, grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}});
  dbg_test_with(-1, grid = {{0, 1}});

  return EXIT_SUCCESS;
}
