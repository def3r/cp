#include "dbg.h"

long long zeroFilledSubarray(vector<int> &nums) {
  long long res = 0, count = 0;
  for (int num : nums) {
    if (num == 0) {
      count++;
    } else {
      res += (count * (count + 1)) / 2;
      count = 0;
    }
  }
  res += (count * (count + 1)) / 2;
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun zeroFilledSubarray(nums)

  dbg_test_with(6, nums = {1, 3, 0, 0, 2, 0, 0, 4});
  dbg_test_with(9, nums = {0, 0, 0, 2, 0, 0});
  dbg_test_with(0, nums = {2, 10, 2019});

  return EXIT_SUCCESS;
}
