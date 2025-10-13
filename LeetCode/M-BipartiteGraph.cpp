#include "dbg.h"
#include <vector>

bool dfs(vector<vector<int>> &graph, vector<int> &color, int vertex) {
  for (int v : graph[vertex]) {
    if (color[v] == -1) {
      color[v] = (color[vertex] == 0);
      if (!dfs(graph, color, v)) {
        return false;
      }
    } else if (color[v] == color[vertex]) {
      return false;
    }
  }
  return true;
}

bool isBipartite(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> color(n, -1);

  for (int i = 0; i < n; i++) {
    if (color[i] != -1)
      continue;
    color[i] = 0;
    if (!dfs(graph, color, i))
      return false;
  }

  return true;
}

bool isBipartiteBFS(vector<vector<int>> &graph) {
  int n = graph.size();
  vector<int> color(n, -1);
  queue<int> q = {};

  for (int i = 0; i < n; i++) {
    if (color[i] != -1)
      continue;
    color[i] = 0;
    q.push(i);
    while (!q.empty()) {
      int front = q.front();
      q.pop();

      for (int vertex : graph[front]) {
        if (color[vertex] == -1) {
          color[vertex] = (color[front] == 0);
          q.push(vertex);
        } else if (color[vertex] == color[front]) {
          return false;
        }
      }
    }
  }

  return true;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
