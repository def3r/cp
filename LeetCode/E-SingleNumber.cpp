#include "dbg.h"

int singleNumber(vector<int> &nums) {
  int n = 0;
  for (int num : nums) {
    n ^= num;
  }
  return n;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun singleNumber(nums)
  dbg_test_with(1, nums = {2, 2, 1});
  dbg_test_with(4, nums = {4, 1, 2, 1, 2});
  dbg_test_with(1, nums = {1});

  return EXIT_SUCCESS;
}
