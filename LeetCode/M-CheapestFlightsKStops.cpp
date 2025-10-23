#include "dbg.h"

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                      int k) {
  vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>{});
  vector<int> costV(n, INT_MAX);
  for (auto &flight : flights) {
    adj[flight[0]].push_back({flight[1], flight[2]});
  }

  queue<tuple<int, int, int>> q{};
  q.push({0, src, 0});
  costV[src] = 0;
  while (!q.empty()) {
    auto [stops, node, cost] = q.front();
    q.pop();

    for (auto &it : adj[node]) {
      if (costV[it.first] > cost + it.second && stops <= k) {
        costV[it.first] = cost + it.second;
        q.push({stops + 1, it.first, costV[it.first]});
      }
    }
  }

  return costV[dst] == INT_MAX ? -1 : costV[dst];
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
