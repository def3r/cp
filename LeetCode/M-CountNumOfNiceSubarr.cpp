#include "dbg.h"

int helper(vector<int> &nums, int k) {
  int count = 0, oddCount = 0;
  int l = 0, r = 0;
  int n = nums.size();

  while (r < n) {
    oddCount += (nums[r] & 1);
    while (oddCount > k) {
      oddCount -= (nums[l++] & 1);
    }
    count += (r - l + 1);
    r++;
  }

  return count;
}

int numberOfSubarrays(vector<int> &nums, int k) {
  return helper(nums, k) - helper(nums, k - 1);
}

#undef dbg_test_fun
int main() {
  vector<int> nums;
  int k;

#define dbg_test_fun numberOfSubarrays(nums, k)
  dbg_test_with(2, nums = {1, 1, 2, 1, 1}, k = 3);
  dbg_test_with(0, nums = {2, 4, 6}, k = 1);
  dbg_test_with(16, nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2}, k = 2);

  return EXIT_SUCCESS;
}
