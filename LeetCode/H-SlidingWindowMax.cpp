#include <deque>
#define dbg_expect_1DV
#include "dbg.h"

vector<int> maxSlidingWindow(vector<int> &nums, int k) {
  vector<int> res = {};
  deque<int> d;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    if (!d.empty() && d.front() < i - k + 1) {
      d.pop_front();
    }
    while (!d.empty() && nums[d.back()] <= nums[i]) {
      d.pop_back();
    }
    d.push_back(i);
    if (i >= k - 1) {
      res.push_back(nums[d.front()]);
    }
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums, res;
  int k;

#define dbg_test_fun maxSlidingWindow(nums, k)
  dbg_test_with(res, res = {3, 3, 5, 5, 6, 7},
                nums = {1, 3, -1, -3, 5, 3, 6, 7}, k = 3);
  dbg_test_with(res, res = {3, 3, 2, 5}, nums = {1, 3, 1, 2, 0, 5}, k = 3);

  return EXIT_SUCCESS;
}
