#include "dbg.h"
#include <vector>

void rec(int idx, int sum, vector<int> &res, vector<int> &nums) {
  if (idx < 0) {
    res.push_back(sum);
    return;
  }
  rec(idx - 1, sum + nums[idx], res, nums);
  rec(idx - 1, sum, res, nums);
}

vector<int> subsetSums(vector<int> &nums) {
  vector<int> res;
  rec(nums.size() - 1, 0, res, nums);
  dbg_print_each(res);
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun subsetSums(nums)
  nums = {2, 3};
  dbg_test_fun;

  nums = {5, 2, 1};
  dbg_test_fun;

  return EXIT_SUCCESS;
}
