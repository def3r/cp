#include "dbg.h"
#include <vector>

bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, int vertex,
         int edges, int &depth) {
  visited[vertex] = true;
  depth++;
  bool res = true;
  if (adjList[vertex].size() != edges)
    res = false;
  for (int v : adjList[vertex]) {
    if (!visited[v] && !dfs(adjList, visited, v, edges, depth))
      res = false;
  }
  return res;
}

int countCompleteComponents(int n, vector<vector<int>> &edges) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> adjList(n);
  for (const auto &edge : edges) {
    adjList[edge[0]].push_back(edge[1]);
    adjList[edge[1]].push_back(edge[0]);
  }
  vector<bool> visited(n, false);
  int res = 0;

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      int depth = 0, edgesFromVertex = adjList[i].size();
      int valid = dfs(adjList, visited, i, edgesFromVertex, depth);
      res += (valid && depth - 1 == edgesFromVertex);
    }
  }

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
