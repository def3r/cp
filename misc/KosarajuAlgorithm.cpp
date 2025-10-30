#include "dbg.h"
#include <stack>
#include <vector>

// mtext solution
class Solution {
  void dfs(int v, vector<char> &visited, vector<int> adj[], stack<int> &s) {
    visited[v] = 1;
    for (int vertex : adj[v]) {
      if (!visited[vertex]) {
        dfs(vertex, visited, adj, s);
      }
    }
    s.push(v);
  }

  void dfs(int v, vector<char> &visited, vector<vector<int>>& adj) {
    visited[v] = 1;
    for (int vertex : adj[v]) {
      if (!visited[vertex]) {
        dfs(vertex, visited, adj);
      }
    }
  }

public:
  int kosaraju(int V, vector<int> adj[]) {
    stack<int> finalTime{};
    vector<char> visited(V, 0);
    for (int i = 0; i < V; i++) {
      if (!visited[i])
        dfs(i, visited, adj, finalTime);
    }

    vector<vector<int>> revAdj(V, vector<int>{});
    for (int i = 0; i < V; i++) {
      for (int vertex : adj[i]) {
        revAdj[vertex].push_back(i);
      }
    }

    int sccCount = 0;
    visited = vector<char>(V, 0);
    while (!finalTime.empty()) {
      int top = finalTime.top();
      if (!visited[top]) {
        dfs(top, visited, revAdj);
        sccCount++;
      }
      finalTime.pop();
    }

    return sccCount;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
