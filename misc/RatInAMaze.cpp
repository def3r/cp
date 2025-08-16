#include "dbg.h"

// TC -> O(4 ^ (N^2))

void recFun(int row, int col, int bufIdx, char *buf, vector<string> &res,
            vector<vector<int>> &grid) {
  if (row < 0 || row >= grid.size() || col < 0 || col >= grid.size()) {
    return;
  }

  if (grid[row][col] == 0) {
    return;
  }

  if (row == grid.size() - 1 && col == grid.size() - 1) {
    res.push_back(buf);
    return;
  }

  grid[row][col] = 0;

  buf[bufIdx] = 'U';
  recFun(row - 1, col, bufIdx + 1, buf, res, grid);

  buf[bufIdx] = 'R';
  recFun(row, col + 1, bufIdx + 1, buf, res, grid);

  buf[bufIdx] = 'D';
  recFun(row + 1, col, bufIdx + 1, buf, res, grid);

  buf[bufIdx] = 'L';
  recFun(row, col - 1, bufIdx + 1, buf, res, grid);

  grid[row][col] = 1;
  buf[bufIdx] = '\0';
}

vector<string> findPath(vector<vector<int>> &grid) {
  vector<string> res;
  int n = grid.size();
  char buf[n * n + 1];
  memset(buf, '\0', n * n + 1);
  recFun(0, 0, 0, buf, res, grid);
  dbg_print_each(res);
  return res;
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> grid;

#define dbg_test_fun findPath(grid)
  grid = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  dbg_test_fun;

  grid = {{1, 0}, {1, 0}};
  dbg_test_fun;

  grid = {{1, 1, 1}, {1, 1, 1}, {0, 1, 1}};
  dbg_test_fun;

  return EXIT_SUCCESS;
}
