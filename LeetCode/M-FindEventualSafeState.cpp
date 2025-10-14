#include "dbg.h"
#include <vector>

class Solution {
public:
  bool dfs(vector<vector<int>> &graph, vector<bool> &visited,
           vector<bool> &path, vector<bool> &accepted, int vertex) {
    visited[vertex] = true;
    path[vertex] = true;

    for (int i : graph[vertex]) {
      if (visited[i] && path[i])
        return false;
      else if (visited[i] && !path[i] && accepted[i])
        continue;
      if (!dfs(graph, visited, path, accepted, i)) {
        return false;
      }
    }

    path[vertex] = false;
    return accepted[vertex] = true;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> visited(n, false), path(n, false);
    vector<bool> accepted(n, false);
    vector<int> res = {};

    for (int i = 0; i < n; i++)
      if (!visited[i])
        dfs(graph, visited, path, accepted, i);

    for (int i = 0; i < n; i++)
      if (accepted[i])
        res.push_back(i);

    return res;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
