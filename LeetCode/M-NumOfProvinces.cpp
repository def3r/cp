#include "dbg.h"
#include <vector>

void dfs(vector<vector<int>> &adjList, vector<bool> &visited, int vertex) {
  visited[vertex] = true;
  for (int i = 0; i < adjList.size(); i++) {
    if (adjList[vertex][i] == 0)
      continue;
    if (!visited[i])
      dfs(adjList, visited, i);
  }
}

int findCircleNum(vector<vector<int>> &isConnected) {
  int n = isConnected.size();
  int provinces = 0;
  vector<bool> visited(n, false);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      provinces++;
      dfs(isConnected, visited, i);
    }
  }

  return provinces;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
