#include "dbg.h"
#include <unordered_map>
#include <vector>

// mtext solution
class Solution {
  struct UnionFind {
    vector<int> parent{}, size{};
    int n, m;

    UnionFind(int n, int m) : n(n), m(m) {
      size = vector<int>(n + m, 0);
      parent = vector<int>(n + m);
      for (int i = 0; i < n + m; i++) {
        parent[i] = i;
      }
    }

    int findParent(int u) {
      if (parent[u] == u)
        return u;
      return parent[u] = findParent(parent[u]);
    }

    void assign(int u) { size[u] += size[u] == 0; }

    void unionBySize(int u, int v) {
      int pu = findParent(u), pv = findParent(v);
      if (pu == pv)
        return;

      assign(pu);
      assign(pv);
      if (size[pu] >= size[pv]) {
        parent[pv] = pu;
        size[pu] += size[pv];
      } else {
        parent[pu] = pv;
        size[pv] += size[pu];
      }
    }
  };

public:
  int removeStones(vector<vector<int>> &stones) {
    int mRows = 0, mCols = 0;
    for (auto &coords : stones) {
      mRows = max(mRows, coords[0]);
      mCols = max(mCols, coords[1]);
    }

    UnionFind uf(mRows + 1, mCols + 1);
    for (auto &coords : stones) {
      uf.unionBySize(coords[0], mRows + 1 + coords[1]);
    }

    int comps = 0;
    for (int i = 0; i < mRows + mCols + 2; i++) {
      comps += (uf.findParent(i) == i && uf.size[i] != 0);
    }

    return stones.size() - comps;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
