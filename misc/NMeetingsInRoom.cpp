#include "dbg.h"
#include <vector>

int maxMeetings(vector<int> &start, vector<int> &end) {
  vector<vector<int>> sched = {};
  int size = start.size();
  sched.reserve(size);
  for (int idx = 0; idx < size; idx++) {
    sched.push_back({start[idx], end[idx]});
  }
  sort(sched.begin(), sched.end(),
       [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });

  int res = 0;
  int currentTime = 0;
  for (int idx = 0; idx < size; idx++) {
    if (sched[idx][0] > currentTime) {
      res++;
      currentTime = sched[idx][1];
    }
  }
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> start, end;

#define dbg_test_fun maxMeetings(start, end)

  return EXIT_SUCCESS;
}
