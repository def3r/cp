#include "dbg.h"
#include <string>
#include <unordered_set>
#include <vector>

int drow[4] = {1, -1, 0, 0};
int dcol[4] = {0, 0, 1, -1};

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row,
         int col, int cur_row, int cur_col, stringstream &ss) {
  int m = grid.size(), n = grid[0].size();
  visited[cur_row][cur_col] = true;
  ss << row - cur_row << "," << col - cur_col << " ";

  int x, y;
  for (int i = 0; i < 4; i++) {
    x = cur_row + drow[i];
    y = cur_col + dcol[i];
    if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 &&
        !visited[x][y]) {
      dfs(grid, visited, row, col, x, y, ss);
    }
  }
}

int countDistinctIslands(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<bool>> visited(m, vector<bool>(n, false));
  unordered_set<string> st;

  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == 1 && !visited[row][col]) {
        stringstream ss = {};
        dfs(grid, visited, row, col, row, col, ss);
        st.insert(ss.str());
      }
    }
  }

  return st.size();
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
