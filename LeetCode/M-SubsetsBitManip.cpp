#define dbg_expect_2DV
#include "dbg.h"

vector<vector<int>> powerSet(vector<int> &nums) {
  vector<vector<int>> res = {};
  int size = nums.size();
  int count = (1 << size);

  for (int i = 0; i < count; i++) {
    vector<int> sub = {};
    for (int j = 0; j < size; j++) {
      if ((i & (1 << j)) != 0) {
        sub.push_back(nums[j]);
      }
    }
    res.push_back(sub);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums = {};
  vector<vector<int>> res = {};

#define dbg_test_fun powerSet(nums);
  dbg_test_with(res,
                res = {{}, {1}, {2}, {1, 2}, {3}, {1, 3}, {2, 3}, {1, 2, 3}},
                nums = {1, 2, 3});

  return EXIT_SUCCESS;
}
