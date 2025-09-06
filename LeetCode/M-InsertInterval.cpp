#include "dbg.h"

vector<vector<int>> insert(vector<vector<int>> &intervals,
                           vector<int> &newInterval) {
  vector<vector<int>> res;
  int idx = 0;
  int n = intervals.size();

  // left half
  while (idx < n && intervals[idx][1] < newInterval[0]) {
    res.push_back(intervals[idx++]);
  }

  // possible merging
  while (idx < n && intervals[idx][0] <= newInterval[1]) {
    newInterval[0] = min(newInterval[0], intervals[idx][0]);
    newInterval[1] = max(newInterval[1], intervals[idx][1]);
    idx++;
  }
  res.push_back(newInterval);

  while (idx < n) {
    res.push_back(intervals[idx++]);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> intervals, newInterval;

#define dbg_test_fun insert(intervals, newInterval)

  return EXIT_SUCCESS;
}
