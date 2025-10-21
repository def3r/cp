#include "dbg.h"
#include <algorithm>
#include <unordered_map>
#include <vector>

bool dfs(int v, vector<int> &path, int cost, unordered_map<int, int> &dist,
         vector<vector<pair<int, int>>> &adj) {
  if (v == 1 && cost == 0) {
    return true;
  }
  if (cost < 0) {
    return false;
  }

  int distCost = dist[v];
  dist.erase(v);
  for (auto vertex : adj[v]) {
    if (dist.find(vertex.first) == dist.end()) {
      continue;
    }
    path.push_back(vertex.first);
    if (dfs(vertex.first, path, cost - vertex.second, dist, adj)) {
      dist[v] = distCost;
      return true;
    }
    path.pop_back();
  }
  dist[v] = distCost;

  return false;
}

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
  set<pair<int, int>> s;
  unordered_map<int, int> dist;
  vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>{});
  vector<int> res{};

  for (int i = 1; i <= n; i++) {
    dist[i] = INT_MAX;
  }

  for (auto edge : edges) {
    adj[edge[0]].push_back({edge[1], edge[2]});
    adj[edge[1]].push_back({edge[0], edge[2]});
  }

  s.insert({0, 1});
  dist[1] = 0;
  while (!s.empty()) {
    pair<int, int> front = *s.begin();
    s.erase(s.begin());

    for (pair<int, int> v : adj[front.second]) {
      if (dist[v.first] > front.first + v.second) {
        dist[v.first] = front.first + v.second;
        s.insert({dist[v.first], v.first});
      }
    }
  }
  if (dist[n] == INT_MAX) {
    return {-1};
  }

  res.push_back(n);
  dfs(n, res, dist[n], dist, adj);
  res.push_back(dist[n]);

  reverse(res.begin(), res.end());
  return res;
}

#undef dbg_test_fun
int main() {
  int n;
  int m;
  vector<vector<int>> edges;

#define dbg_test_fun shortestPath(n, m, edges);

  edges = {{6, 9, 4},       {14, 7, 3},      {10, 22, 12},    {11, 5, 10},
           {13, 14, 12},    {12, 9, 8},      {25, 20, 24},    {28, 11, 2},
           {4, 28, 8},      {17, 25, 25},    {21, 25, 2},     {27, 2, 20},
           {5, 23, 8},      {16, 9, 0},      {17, 3, 7},      {23, 1, 0},
           {18, 17, 24},    {6, 15, 4},      {24, 27, 25},    {26, 9, 4},
           {19, 9, 12},     {16, 8, 22},     {20, 22, 5099},  {13, 23, 88823},
           {28, 18, 31287}, {19, 25, 61316}, {5, 2, 91841},   {27, 22, 84509},
           {24, 8, 85821},  {10, 28, 73469}, {14, 17, 43743}, {16, 22, 21739},
           {21, 3, 35357},  {11, 7, 73099},  {25, 13, 15427}, {23, 9, 70462},
           {3, 9, 64644},   {5, 10, 15369},  {9, 1, 32980},   {5, 2, 52249},
           {12, 24, 27299}, {16, 27, 32280}, {13, 2, 69723}};

  shortestPath(n = 28, m = 39, edges);

  return EXIT_SUCCESS;
}
