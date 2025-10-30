#include "dbg.h"
#include <vector>

// mtext solution
class Solution {
  void dfs(int parent, int idx, vector<vector<int>> &adj, vector<char> &visited,
           vector<vector<int>> &res) {
    visited[idx] = 1;
    time[idx] = time[parent] + 1;
    low[idx] = time[idx];

    for (int vertex : adj[idx]) {
      if (vertex == parent)
        continue;

      if (!visited[vertex]) {
        dfs(idx, vertex, adj, visited, res);
        low[idx] = min(low[idx], low[vertex]);
        if (low[vertex] > time[idx]) {
          res.push_back({idx, vertex});
        }
      } else {
        low[idx] = min(low[idx], low[vertex]);
      }
    }
  }

  vector<int> time, low;

public:
  vector<vector<int>> criticalConnections(int n,
                                          vector<vector<int>> &connections) {
    vector<vector<int>> adj(n, vector<int>{});
    vector<char> visited(n, 0);
    vector<vector<int>> res{};

    time = vector<int>(n);
    low = vector<int>(n, INT_MAX);
    for (int i = 0; i < connections.size(); i++) {
      adj[connections[i][0]].push_back(connections[i][1]);
      adj[connections[i][1]].push_back(connections[i][0]);
    }

    time[0] = 0;
    dfs(0, 0, adj, visited, res);

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
