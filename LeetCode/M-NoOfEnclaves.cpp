#include "dbg.h"
#include <vector>

int numEnclaves(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  int count1 = 0;
  int boundary = 0;
  queue<pair<int, int>> q = {};

  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == 1) {
        count1++;
        grid[row][col] = 2;
      }
      if ((col == 0 || row == 0 || row == m - 1 || col == n - 1) &&
          grid[row][col] > 0) {
        q.push({row, col});
        grid[row][col] = 0;
        boundary++;

        while (!q.empty()) {
          pair<int, int> front = q.front();
          q.pop();

          int x, y;
          x = front.first;
          for (int dir_col = -1; dir_col <= 1; dir_col += 2) {
            y = front.second + dir_col;
            if (y >= 0 && y < n && grid[x][y] > 0) {
              if (grid[x][y] == 1) {
                count1++;
              }
              boundary++;
              grid[x][y] = 0;
              q.push({x, y});
            }
          }

          y = front.second;
          for (int dir_row = -1; dir_row <= 1; dir_row += 2) {
            x = front.first + dir_row;
            if (x >= 0 && x < m && grid[x][y] > 0) {
              if (grid[x][y] == 1) {
                count1++;
              }
              boundary++;
              grid[x][y] = 0;
              q.push({x, y});
            }
          }
        }
      }
    }
  }
  return count1 - boundary;
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> grid;

#define dbg_test_fun numEnclaves(grid);
  dbg_test_with(3, grid = {{0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                           {1, 1, 0, 0, 0, 1, 0, 1, 1, 1},
                           {0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                           {0, 1, 1, 0, 0, 0, 1, 0, 1, 0},
                           {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
                           {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                           {0, 1, 1, 0, 0, 0, 1, 1, 1, 1},
                           {0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
                           {1, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 1, 0, 0, 0, 1}});

  return EXIT_SUCCESS;
}
