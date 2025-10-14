#include "dbg.h"

bool dfs(vector<int> adj[], vector<bool> &visited, vector<bool> &path,
         int vertex) {
  visited[vertex] = true;
  path[vertex] = true;
  for (int v : adj[vertex]) {
    if (visited[v] && path[v])
      return true;
    if (dfs(adj, visited, path, v))
      return true;
  }
  path[vertex] = false;
  return false;
}
bool isCyclic(int N, vector<int> adj[]) {
  vector<bool> visited(N, false);
  vector<bool> path(N, false);

  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      if (dfs(adj, visited, path, i))
        return true;
    }
  }

  return false;

  queue<int> q = {};

  for (int i = 0; i < N; i++) {
    if (visited[i])
      continue;

    visited[i] = true;
    q.push(i);

    while (!q.empty()) {
      int front = q.front();
      q.pop();

      for (int v : adj[front]) {
        if (visited[v])
          return true;
        visited[v] = true;
        q.push(v);
      }
    }
  }

  return false;
}

bool isCyclicBFS(int N, vector<int> adj[]) {
  vector<int> indeg(N, 0);
  queue<int> q = {};
  int count = 0;

  for (int i = 0; i < N; i++) {
    for (int v : adj[i])
      indeg[v]++;
  }

  for (int i = 0; i < N; i++) {
    if (indeg[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int front = q.front();
    q.pop();
    count++;

    for (int v : adj[front]) {
      if (--indeg[v] == 0)
        q.push(v);
    }
  }

  return count != N;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
