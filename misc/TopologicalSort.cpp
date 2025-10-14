#include "dbg.h"
#include <queue>
#include <vector>

vector<int> topoSort(int V, vector<int> adj[]) {
  vector<int> indeg(V, 0);
  vector<int> res = {};
  res.reserve(V);
  queue<int> q = {};

  for (int i = 0; i < V; i++) {
    for (int vertex : adj[i]) {
      indeg[vertex]++;
    }
  }

  for (int i = 0; i < V; i++) {
    if (indeg[i] == 0)
      q.push(i);
  }

  while (!q.empty()) {
    int front = q.front();
    q.pop();
    res.push_back(front);

    for (int vertex : adj[front]) {
      if (indeg[vertex] == 0)
        continue;
      if (--indeg[vertex] == 0) {
        q.push(vertex);
      }
    }
  }

  dbg_print_each(res);

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func
  vector<int> adj[] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
  topoSort(6, adj);

  return EXIT_SUCCESS;
}
