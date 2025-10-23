#include "dbg.h"
#include <climits>
#include <queue>
#include <vector>

int minimumMultiplications(vector<int> &arr, int start, int end) {
  vector<int> dist(99999, INT_MAX);
  queue<tuple<int, long long>> q{};

  if (start == end)
    return 0;

  q.push({0, start});
  while (!q.empty()) {
    auto [steps, node] = q.front();
    q.pop();

    for (int num : arr) {
      int idx = (node * num) % (long long)1e5;
      if (idx == end) {
        return steps + 1;
      }
      if (dist[idx] > steps + 1) {
        dist[idx] = steps + 1;
        q.push({steps + 1, idx});
      }
    }
  }

  return -1;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func
  int start = 7, end = 66175;
  vector<int> arr;
  arr = {3, 4, 65};

  minimumMultiplications(arr, start, end);

  return EXIT_SUCCESS;
}
