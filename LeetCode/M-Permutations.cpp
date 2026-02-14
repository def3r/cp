#include "dbg.h"
#include <vector>

// mtext solution
class Solution {
  vector<vector<int>> res{};
  static constexpr int res_size[] = {1, 2, 6, 24, 120, 720};

  void func(vector<int> &nums, int size) {
    if (size < 0) {
      res.push_back(nums);
      return;
    }

    for (int i = 0; i <= size; i++) {
      swap(nums[i], nums[size]);
      func(nums, size - 1);
      swap(nums[i], nums[size]);
    }
  }

public:
  vector<vector<int>> permute(vector<int> &nums) {
    res.reserve(res_size[nums.size() - 1]); // from 21% to 98% better in space
    func(nums, nums.size() - 1);
    return res;
  }
};
// mtext solution

#undef dbg_test_fun
int main() {
  Solution solution;

#define dbg_test_fun solution.permute(nums);

  return EXIT_SUCCESS;
}
