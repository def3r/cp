#include "dbg.h"
#include <queue>
#include <utility>
#include <vector>

int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
  int n = grid.size();
  vector<vector<char>> visited(n, vector<char>(n, 0));
  queue<pair<int, int>> q{};
  int lvl = 0;

  if (grid[0][0] == 1)
    return -1;
  if (n == 1)
    return 1;

  q.push({0, 0});
  visited[0][0] = 1;
  while (!q.empty()) {
    lvl++;
    int size = q.size();

    while (size--) {
      pair<int, int> front = q.front();
      q.pop();

      int x, y;
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          x = front.first + i;
          y = front.second + j;
          if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 0 &&
              !visited[x][y]) {
            if (x == n - 1 && y == n - 1)
              return lvl + 1;
            q.push({x, y});
            visited[x][y] = 1;
          }
        }
      }
    }
  }

  return -1;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
