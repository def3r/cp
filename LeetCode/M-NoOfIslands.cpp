#include "dbg.h"
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

int numIslands(vector<vector<char>> &grid) {
  int m = grid.size(), n = grid[0].size();
  bool visited[m][n];
  memset(visited, false, m * n * sizeof(bool));
  queue<pair<int, int>> q = {};
  int islandCount = 0;

  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (grid[row][col] == '1' && !visited[row][col]) {
        islandCount++;
        q.push({row, col});
        while (!q.empty()) {
          pair<int, int> front = q.front();
          q.pop();

          // clang-format off
          int x, y;
          // up
          x = front.first - 1, y = front.second;
          if (x >= 0 && grid[x][y] == '1' && !visited[x][y]) { visited[x][y] = true; q.push({x, y}); }
          // down
          x = front.first + 1, y = front.second;
          if (x < m && grid[x][y] == '1' && !visited[x][y]) { visited[x][y] = true; q.push({x, y}); }
          // left
          x = front.first, y = front.second - 1;
          if (y >= 0 && grid[x][y] == '1' && !visited[x][y]) { visited[x][y] = true; q.push({x, y}); }
          // right
          x = front.first, y = front.second + 1;
          if (y < n && grid[x][y] == '1' && !visited[x][y]) { visited[x][y] = true; q.push({x, y}); }
          // clang-format on
        }
      }
    }
  }

  return islandCount;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
