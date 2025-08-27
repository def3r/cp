#include <vector>
#define dbg_expect_1DV
#include "dbg.h"

vector<int> singleNumber(vector<int> &nums) {
  long long x = 0;
  for (int num : nums) {
    x ^= num;
  }

  long long firstSetBit = (x & (x - 1)) ^ x;
  int b1 = 0, b2 = 0;
  for (int num : nums) {
    if ((num & firstSetBit) == firstSetBit) {
      b1 ^= num;
    } else {
      b2 ^= num;
    }
  }

  return (b1 > b2) ? vector<int>{b2, b1} : vector<int>{b1, b2};
}

#undef dbg_test_fun
int main() {
  vector<int> nums, res;

#define dbg_test_fun singleNumber(nums)
  dbg_test_with(res, nums = {1, 2, 1, 3, 2, 5}, res = {3, 5});
  dbg_test_with(res, nums = {-1, 0}, res = {-1, 0});
  dbg_test_with(res, nums = {1, 0}, res = {1, 0});

  return EXIT_SUCCESS;
}
