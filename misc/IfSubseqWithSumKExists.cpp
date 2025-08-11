#include "dbg.h"

// Optmial Sol
// but takes 372 ms (lol)
bool checkSubseqRecOpt(int idx, int sum, vector<int> &nums) {
  if (idx == nums.size()) {
    return sum == 0;
  }
  return checkSubseqRecOpt(idx + 1, sum - nums[idx], nums) |
         checkSubseqRecOpt(idx + 1, sum, nums);
}

// Naive Approach
// But takes only 47 ms
bool checkSubseqRec(int accumulator, vector<int>::iterator it, int &k,
                    vector<int> &nums) {
  if (it == nums.end()) {
    return accumulator == k;
  }
  if (accumulator > k) {
    return false;
  }
  accumulator += *it;
  if (accumulator == k) {
    return true;
  } else if (checkSubseqRec(accumulator, it + 1, k, nums)) {
    return true;
  }
  return checkSubseqRec(accumulator - *it, it + 1, k, nums);
}

bool checkSubsequenceSum(vector<int> &nums, int k) {
  if (k > accumulate(nums.begin(), nums.end(), 0)) {
    return false;
  }
  // return checkSubseqRec(0, nums.begin(), k, nums);
  return checkSubseqRecOpt(0, k, nums);
}

#undef dbg_test_fun
int main() {
  vector<int> nums;
  int k;

#define dbg_test_fun checkSubsequenceSum(nums, k)
  dbg_test_with(true, nums = {1, 2, 3, 4, 5}, k = 8);
  dbg_test_with(false, nums = {4, 3, 9, 2}, k = 10);
  dbg_test_with(true, nums = {1, 10, 4, 5}, k = 16);

  return EXIT_SUCCESS;
}
