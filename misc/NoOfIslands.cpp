#include "dbg.h"
#include <vector>

// mtext solution
class Solution {
  struct UnionFind {
    vector<int> parent, size;
    vector<int> res{};
    int n, m;
    int count = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    UnionFind(int n, int m) : n(n), m(m) {
      size = vector<int>(n * m, 0);
      parent = vector<int>(n * m);
      for (int i = 0; i < n * m; i++) {
        parent[i] = i;
      }
    }

    int findParent(int i) {
      if (parent[i] == i)
        return i;
      return parent[i] = findParent(parent[i]);
    }

    void merge(int u, int v) {
      int pu = findParent(u), pv = findParent(v);
      if (size[pu] >= size[pv]) {
        parent[pv] = pu;
        size[pu] += size[pv];
      } else {
        parent[pu] = pv;
        size[pv] += size[pu];
      }
      count--;
    }

    void insert(int u) {
      int pu = findParent(u);
      if (size[pu] == 0) {
        size[pu]++;
        count++;

        int row = u / m;
        int col = u % m;
        for (int i = 0; i < 4; i++) {
          int y = col + dy[i];
          int x = row + dx[i];
          if (x >= 0 && x < n && y >= 0 && y < m) {
            int idx = x * m + y;
            if (size[idx] > 0 && findParent(idx) != findParent(u)) {
              merge(idx, u);
            }
          }
        }
      }

      res.push_back(count);
    }
  };

public:
  vector<int> numOfIslands(int n, int m, vector<vector<int>> &A) {
    UnionFind uf(n, m);
    for (auto &land : A) {
      uf.insert(land[0] * m + land[1]);
    }

    return uf.res;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;
  int n = 4, m = 5, k = 12;
  vector<vector<int>> A = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3},
                           {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

#define dbg_test_fun // func
  solution.numOfIslands(n, m, A);

  return EXIT_SUCCESS;
}
