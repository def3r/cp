#define dbg_expect_1DV
#include "dbg.h"
#include <stack>

vector<int> nextGreaterElements(vector<int> &nums) {
  int n = nums.size();
  vector<int> res(n, -1);
  stack<int> s;
  int idx = n - 1;
  if (idx == 0)
    return res;

  for (idx = n - 2; idx >= 0; idx--) {
    s.push(nums[idx]);
  }

  for (idx = n - 1; idx >= 0; idx--) {
    while (!s.empty() && s.top() <= nums[idx]) {
      s.pop();
    }
    res[idx] = (s.empty()) ? -1 : s.top();
    s.push(nums[idx]);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums, res;

#define dbg_test_fun nextGreaterElements(nums)
  dbg_test_with(res, res = {2, -1, 2}, nums = {1, 2, 1});

  return EXIT_SUCCESS;
}
