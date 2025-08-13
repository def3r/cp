#include "dbg.h"
#include <vector>

void rec(int idx, vector<int> &v, vector<vector<int>> &res, vector<int> &nums) {
  if (idx < 0) {
    res.push_back(v);
    return;
  }
  v.push_back(nums[idx]);
  rec(idx - 1, v, res, nums);
  v.pop_back();

  for (int i = idx - 1; i >= 0; i--) {
    if (nums[idx] != nums[i]) {
      rec(i, v, res, nums);
      return;
    }
  }
  res.push_back(v);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  vector<vector<int>> res;
  vector<int> v;
  sort(nums.begin(), nums.end());

  rec(nums.size() - 1, v, res, nums);
  for (vector<int> list : res) {
    dbg_print_each(list);
  }
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun subsetsWithDup(nums)
  nums = {1, 2, 2};
  dbg_test_fun;

  nums = {0};
  dbg_test_fun;

  nums = {1, 2};
  dbg_test_fun;

  return EXIT_SUCCESS;
}
