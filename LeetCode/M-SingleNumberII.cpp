#include "dbg.h"
#include <algorithm>

// Bit Manipulation
// TC: O(32 * nums.size) = O(32N) = O(N)
int singleNumber(vector<int> &nums) {
  int res = 0;
  for (int i = 0; i < 32; i++) {
    int count1 = 0;
    for (int num : nums) {
      count1 += (((num >> i) & 1) == 1);
    }
    if (count1 % 3 != 0) {
      res = res | (1 << i);
    }
  }
  return res;
}

// No Bit Manipulation
// TC: O(nlogn + n/3)
int singleNumberNoBitMan(vector<int> &nums) {
  sort(nums.begin(), nums.end());
  for (int idx = 1; idx < nums.size(); idx += 3) {
    if (nums[idx - 1] != nums[idx]) {
      return nums[idx - 1];
    }
  }
  return *(nums.end() - 1);
}

// Bit Manipulation Optimal Sol
// TC: O(n)
int singleNumberOptimal(vector<int> &nums) {
  int ones = 0, twos = 0; // threes = 0 but not needed
  for (int num : nums) {
    ones = (ones ^ num) & ~twos;
    twos = (twos ^ num) & ~ones;
  }
  return ones;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun singleNumberOptimal(nums);
  dbg_test_with(3, nums = {2, 2, 3, 2});
  dbg_test_with(99, nums = {0, 1, 0, 1, 0, 1, 99});

  return EXIT_SUCCESS;
}
