#include "dbg.h"
#include <numeric>
#include <vector>

void countRec(int index, int sum, int &count, vector<int> &nums) {
  if (index == nums.size() | sum <= 0) {
    count += (sum == 0);
    return;
  }
  countRec(index + 1, sum - nums[index], count, nums);
  countRec(index + 1, sum, count, nums);
}

int countSubsequenceWithTargetSum(vector<int> &nums, int k) {
  if (accumulate(nums.begin(), nums.end(), 0) < k)
    return 0;
  int count = 0;
  countRec(0, k, count, nums);
  return count;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;
  int k;

#define dbg_test_fun countSubsequenceWithTargetSum(nums, k)
  dbg_test_with(2, nums = {4, 9, 2, 5, 1}, k = 10);
  dbg_test_with(3, nums = {4, 2, 10, 5, 1, 3}, k = 5);

  return EXIT_SUCCESS;
}
