#include "dbg.h"

int numSubarraysWithSum(vector<int> &nums, int goal) {
  int l = 0, r = 0;
  int sum = 0;
  int count = 0;
  int lIdx = 0, t_sum = 0;
  int n = nums.size();

  while (r < n) {
    sum += nums[r];

    while (sum > goal) {
      sum -= nums[l++];
    }

    lIdx = l;
    int t_sum = sum;
    while (t_sum == goal && lIdx <= r) {
      count++;
      t_sum -= nums[lIdx++];
    }

    r++;
  }

  return count;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;
  int goal;

#define dbg_test_fun numSubarraysWithSum(nums, goal)
  dbg_test_with(4, nums = {1, 0, 1, 0, 1}, goal = 2);
  dbg_test_with(15, nums = {0, 0, 0, 0, 0}, goal = 0);
  dbg_test_with(5, nums = {0, 0, 0, 0, 1}, goal = 1);

  return EXIT_SUCCESS;
}
