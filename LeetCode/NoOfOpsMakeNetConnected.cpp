#include "dbg.h"
#include <algorithm>
#include <vector>

// mtext solution
class Solution {
  struct UnionFind {
    vector<int> size, parent;

    UnionFind(int n) {
      size = vector<int>(n, 1);
      parent.reserve(n);
      for (int i = 0; i < n; i++) {
        parent.push_back(i);
      }
    }

    int findParent(int u) {
      if (parent[u] == u) {
        return u;
      }
      return parent[u] = findParent(parent[u]);
    }

    void merge(int u, int v) {
      int pu = findParent(u), pv = findParent(v);
      if (pu == pv) {
        return;
      }

      if (size[pu] >= size[pv]) {
        parent[pv] = pu;
        size[pu] += size[pv];
      } else {
        parent[pu] = pv;
        size[pv] += size[pu];
      }
    }

    bool find(int u, int v) { return findParent(u) == findParent(v); }
  };

public:
  int makeConnected(int n, vector<vector<int>> &connections) {
    if (connections.size() < n - 1) {
      return -1;
    }

    UnionFind connectedComp(n);
    for (auto &edge : connections) {
      connectedComp.merge(edge[0], edge[1]);
    }

    int steps = 0;
    for (int i = 0; i < n; i++) {
      if (!connectedComp.find(0, i)) {
        connectedComp.merge(0, i);
        steps++;
      }
    }

    return steps;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
