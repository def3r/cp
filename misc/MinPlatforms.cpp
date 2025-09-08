#include "dbg.h"
#include <algorithm>
#include <climits>

int findPlatformOptimal(vector<int> &arrival, vector<int> &departure) {
  int res = 0;
  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());

  int size = arrival.size();
  int count = 0;
  int i = 0, j = 0;
  while (i < size && j < size) {
    if (arrival[i] <= departure[j]) {
      count++;
      i++;
    } else {
      count--;
      j++;
    }
    res = max(res, count);
  }
  return res;
}

// O (NlogN + N) time
// O (N) space
int findPlatform(vector<int> &arrival, vector<int> &departure) {
  priority_queue<int, vector<int>, greater<int>> pq = {};

  vector<vector<int>> v;
  v.reserve(arrival.size());
  for (int idx = 0; idx < arrival.size(); idx++) {
    v.push_back({arrival[idx], departure[idx]});
  }
  sort(v.begin(), v.end(),
       [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

  pq.push(INT_MIN);
  for (const vector<int> &t : v) {
    if (t[0] <= pq.top()) {
      pq.push(t[1]);
    } else {
      pq.pop();
      pq.push(t[1]);
    }
  }

  return pq.size();
}

#undef dbg_test_fun
int main() {
  vector<int> arrival, departure;

#define dbg_test_fun findPlatformOptimal(arrival, departure)
  dbg_test_with(3, arrival = {900, 940, 950, 1100, 1500, 1800},
                departure = {910, 1200, 1120, 1130, 1900, 2000});

  return EXIT_SUCCESS;
}
