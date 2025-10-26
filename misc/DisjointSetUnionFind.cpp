#include "dbg.h"
#include <vector>

// mtext solution
class DisjointSet {
  vector<int> rank, size, parent;

  int findParent(int u) {
    if (parent[u] == u)
      return u;
    return parent[u] = findParent(parent[u]);
  }

public:
  DisjointSet(int n) {
    rank = vector<int>(n + 1, 0);
    size = vector<int>(n + 1, 1);
    parent.push_back(0);
    for (int i = 1; i <= n; i++) {
      parent.push_back(i);
    }
  }

  bool find(int u, int v) { return findParent(u) == findParent(v); }

  void unionByRank(int u, int v) {
    int pu = findParent(u), pv = findParent(v);
    if (pu == pv)
      return;
    if (rank[pu] > rank[pv]) {
      parent[pv] = pu;
    } else if (rank[pu] < rank[pv]) {
      parent[pu] = pv;
    } else {
      parent[pv] = pu;
      rank[pu]++;
    }
  }

  void unionBySize(int u, int v) {
    int pu = findParent(u), pv = findParent(v);
    if (pu == pv)
      return;

    if (size[pu] >= size[pv]) {
      parent[pv] = pu;
      size[pu] += size[pv];
    } else {
      parent[pu] = pv;
      size[pv] += size[pu];
    }
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  // Solution solution;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
