#include "dbg.h"
#include <climits>
#include <functional>
#include <queue>
#include <vector>

int countPaths(int n, vector<vector<int>> &roads) {
  vector<vector<tuple<int, int>>> adj(n, vector<tuple<int, int>>{});
  for (auto road : roads) {
    adj[road[0]].push_back({road[1], road[2]});
    adj[road[1]].push_back({road[0], road[2]});
  }
  vector<long long> dist(n, INT_MAX);
  priority_queue<tuple<long long, int>, vector<tuple<long long, int>>,
                 greater<tuple<long long, int>>>
      pq{};
  vector<long long> pathCnt(n, 0);

  pq.push({0, 0});
  dist[0] = 0;
  pathCnt[0] = 1;
  while (!pq.empty()) {
    auto [d, node] = pq.top();
    pq.pop();

    for (auto [v, wt] : adj[node]) {
      if (dist[v] > d + wt) {
        pathCnt[v] = pathCnt[node];
        dist[v] = d + wt;
        pq.push({dist[v], v});
      } else if (dist[v] == d + wt) {
        pathCnt[v] = (pathCnt[v] + pathCnt[node]) % (int)(1e9 + 7);
      }
    }
  }

  return pathCnt[n - 1] % (int)(1e9 + 7);
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func
  vector<vector<int>> roads = {
      {1, 0, 2348},   {2, 1, 2852},   {2, 0, 5200},   {3, 1, 12480},
      {2, 3, 9628},   {4, 3, 7367},   {4, 0, 22195},  {5, 4, 5668},
      {1, 5, 25515},  {0, 5, 27863},  {6, 5, 836},    {6, 0, 28699},
      {2, 6, 23499},  {6, 3, 13871},  {1, 6, 26351},  {5, 7, 6229},
      {2, 7, 28892},  {1, 7, 31744},  {3, 7, 19264},  {6, 7, 5393},
      {2, 8, 31998},  {8, 7, 3106},   {3, 8, 22370},  {8, 4, 15003},
      {8, 6, 8499},   {8, 5, 9335},   {8, 9, 5258},   {9, 2, 37256},
      {3, 9, 27628},  {7, 9, 8364},   {1, 9, 40108},  {9, 5, 14593},
      {2, 10, 45922}, {5, 10, 23259}, {9, 10, 8666},  {10, 0, 51122},
      {10, 3, 36294}, {10, 4, 28927}, {11, 4, 25190}, {11, 9, 4929},
      {11, 8, 10187}, {11, 6, 18686}, {2, 11, 42185}, {11, 3, 32557},
      {1, 11, 45037}};
  int n = 12;
  cout << countPaths(n, roads);

  return EXIT_SUCCESS;
}
