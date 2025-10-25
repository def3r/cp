#include "dbg.h"
#include <vector>

// mtext solution
class Solution {
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (auto edge : edges) {
      dist[edge[0]][edge[1]] = edge[2];
      dist[edge[1]][edge[0]] = edge[2];
    }
    for (int i = 0; i < n; i++) {
      dist[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            dist[j][i] = dist[i][j];
          }
        }
      }
    }

    int res = 0;
    int cnt = 0;
    int minCnt = n + 1;
    for (int i = 0; i < n; i++) {
      cnt = 0;
      for (int j = 0; j < n; j++) {
        cnt += (dist[i][j] <= distanceThreshold);
      }
      res = (cnt <= minCnt) ? i : res;
      minCnt = min(minCnt, cnt);
    }

    return res;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
