#include "dbg.h"
#include <vector>

int longestOnes(vector<int> &nums, int k) {
  int swapIdx = -1;
  int swaps = 0;
  int maxLen = 0;
  int r = 0;
  int l = 0;
  int n = nums.size();

  while (r < n) {
    if (nums[r] == 0)
      swaps++;
    if (swaps > k) {
      if (nums[l] == 0)
        swaps--;
      l++;
    }
    if (swaps <= k) {
      maxLen = max(maxLen, r - l + 1);
    }
    r++;
  }

  return maxLen;
}

#undef dbg_test_fun
int main() {

  vector<int> nums;
  int k;

#define dbg_test_fun longestOnes(nums, k)
  dbg_test_with(6, nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0}, k = 2);

  return EXIT_SUCCESS;
}
