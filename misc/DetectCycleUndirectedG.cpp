#include "dbg.h"
#include <queue>
#include <vector>

bool dfs(int vertex, int parent, vector<int> adj[], vector<bool> &visited) {
  visited[vertex] = true;

  for (int v : adj[vertex]) {
    if (v == parent)
      continue;
    if (visited[v])
      return true;
    if (dfs(v, vertex, adj, visited))
      return true;
  }

  return false;
}

bool isCycleDFS(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);
  for (int i = 0; i < V; i++) {
    if (visited[i])
      continue;
    if (dfs(i, -1, adj, visited))
      return true;
  }
  return false;
}

bool isCycle(int V, vector<int> adj[]) {
  vector<bool> visited(V, false);
  queue<pair<int, int>> q = {};

  for (int i = 0; i < V; i++) {
    if (visited[i])
      continue;

    visited[i] = true;
    q.push({i, -1});
    while (!q.empty()) {
      pair<int, int> front = q.front();
      q.pop();

      for (int vertex : adj[front.first]) {
        if (vertex == front.second)
          continue;
        if (visited[vertex])
          return true;
        visited[vertex] = true;
        q.push({vertex, front.first});
      }
    }
  }

  return false;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
