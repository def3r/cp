#include "dbg.h"
#include <climits>
#include <stack>
#include <vector>

void dfs(vector<bool> &visited, vector<vector<pair<int, int>>> &adj, int vertex,
         stack<int> &s) {
  visited[vertex] = true;
  for (auto v : adj[vertex]) {
    if (!visited[v.first]) {
      dfs(visited, adj, v.first, s);
    }
  }
  s.push(vertex);
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
  vector<vector<pair<int, int>>> adj(N, vector<pair<int, int>>{});
  vector<bool> visited(N, false);
  vector<int> dist(N, INT_MAX);
  stack<int> s{};

  for (auto &edge : edges) {
    adj[edge[0]].push_back({edge[1], edge[2]});
  }

  dist[0] = 0;
  dfs(visited, adj, 0, s);

  while (!s.empty()) {
    int top = s.top();
    s.pop();

    for (auto v : adj[top]) {
      dist[v.first] = min(dist[v.first], dist[top] + v.second);
    }
  }

  for (int i = 0; i < N; i++) {
    if (dist[i] == INT_MAX)
      dist[i] = -1;
  }

  return dist;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
