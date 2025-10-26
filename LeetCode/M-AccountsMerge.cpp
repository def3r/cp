#include "dbg.h"
#include <unordered_map>
#include <vector>

// mtext solution
class Solution {
  struct UnionFind {
    vector<int> size, parent;
    map<string, int> m;

    UnionFind(int n) {
      size = vector<int>(n, 1);
      parent.reserve(n);
      for (int i = 0; i < n; i++) {
        parent[i] = i;
      }
    }

    int findParent(int u) {
      if (parent[u] == u) {
        return u;
      }
      return parent[u] = findParent(parent[u]);
    }

    void insert(string &s, int idx) { m[s] = idx; }

    int find(string &s) {
      if (m.find(s) == m.end()) {
        return -1;
      }
      return findParent(m[s]);
    }

    void merge(int u, int v) {
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

public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    UnionFind uf(n);
    vector<vector<string>> res{};

    int idx = 0;
    for (auto &acc : accounts) {
      for (int i = 1; i < acc.size(); i++) {
        int accParent = uf.find(acc[i]);
        if (accParent == -1) {
          uf.insert(acc[i], idx);
        } else {
          uf.merge(idx, accParent);
        }
      }
      idx++;
    }

    unordered_map<int, vector<string>> m{};
    for (auto it = uf.m.begin(); it != uf.m.end(); ++it) {
      m[uf.findParent(it->second)].push_back(it->first);
    }

    res.reserve(m.size());
    idx = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
      res.push_back({accounts[it->first][0]});
      for (auto &s : it->second) {
        res[idx].push_back(s);
      }
      idx++;
    }

    return res;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
