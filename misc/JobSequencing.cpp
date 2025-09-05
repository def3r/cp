#include <algorithm>
#include <vector>
#define dbg_expect_1DV
#include "dbg.h"

vector<int> JobScheduling(vector<vector<int>> &jobs) {
  int totalJobs = 0;
  int totalProfit = 0;
  int mostProfitable = 0;
  sort(jobs.begin(), jobs.end(),
       [](vector<int> &a, vector<int> &b) { return a[2] > b[2]; });
  int maxDeadline = (*max_element(
      jobs.begin(), jobs.end(),
      [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; }))[1];

  vector<int> deadline(maxDeadline, -1);
  int it = 0;
  for (vector<int> &job : jobs) {
    it = job[1] - 1;
    while (it >= 0 && deadline[it] != -1)
      it--;
    if (it < 0)
      continue;
    deadline[it] = job[0];
    totalJobs++;
    totalProfit += job[2];
  }

  return {totalJobs, totalProfit};
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> jobs;
  vector<int> res = {};

#define dbg_test_fun JobScheduling(jobs)

  // clang-format off
  dbg_test_with(res,
    res = {2, 60},
    jobs = {
      {1, 4, 20},
      {2, 1, 10},
      {3, 1, 40},
      {4, 1, 30}
    }
  );

  dbg_test_with(res,
    res = {2, 127},
    jobs = {
      {1, 2, 100},
      {2, 1, 19},
      {3, 2, 27},
      {4, 1, 25},
      {5, 1, 15}
    }
  );
  // clang-format on

  return EXIT_SUCCESS;
}
