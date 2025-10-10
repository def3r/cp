#include "dbg.h"
#include <cstring>
#include <queue>
#include <utility>
#include <vector>

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
  int m = mat.size(), n = mat[0].size();
  int visited[m][n];
  memset(visited, 0, m * n * sizeof(int));
  vector<vector<int>> res(m, vector<int>(n, 0));
  queue<pair<int, int>> q = {};

  for (int row = 0; row < m; row++) {
    for (int col = 0; col < n; col++) {
      if (mat[row][col] == 1)
        continue;
      visited[row][col] = 1;
      q.push({row, col});
    }
  }

  int drow[4] = {1, -1, 0, 0};
  int dcol[4] = {0, 0, 1, -1};
  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    level++;

    while (size--) {
      pair<int, int> front = q.front();
      q.pop();

      int x, y;
      for (int i = 0; i < 4; i++) {
        x = front.first + drow[i];
        y = front.second + dcol[i];
        if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
          res[x][y] = level;
          visited[x][y] = 1;
          q.push({x, y});
        }
      }
    }
  }

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func
  vector<vector<int>> mat;
  mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  auto res = updateMatrix(mat);
  for (auto row : res)
    dbg_print_each(row);

  return EXIT_SUCCESS;
}
