#include "dbg.h"
#include <algorithm>
#include <vector>

int MaximumNonOverlappingIntervals(vector<vector<int>> &intervals) {
  sort(intervals.begin(), intervals.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
  int res = 0;
  int currentInterval = 0;
  for (vector<int> interval : intervals) {
    res += (interval[0] >= currentInterval);
    currentInterval =
        (interval[0] >= currentInterval) ? interval[1] : currentInterval;
  }
  return intervals.size() - res;
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> intervals;

#define dbg_test_fun MaximumNonOverlappingIntervals(intervals)

  return EXIT_SUCCESS;
}
