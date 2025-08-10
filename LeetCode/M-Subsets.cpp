#include "dbg.h"
#include <vector>

void powerSetRec(vector<vector<int>> &res, vector<int> &v, vector<int> &nums,
                 int n) {
  if (n == nums.size()) {
    res.push_back(v);
    return;
  }
  v.push_back(nums[n]);
  powerSetRec(res, v, nums, n + 1);
  v.pop_back();
  powerSetRec(res, v, nums, n + 1);
  // Tail recursion
  // Without tail rec: 12.5M (better than 32% leetcode submissions)
  // With tail rec   : 9.64 M (better than 99.56% leetcode submissions)
  // So now you apply tail recursion compiler optimization, leetcode (stupid)
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  vector<int> mid = {};
  vector<vector<int>> res;

  res.reserve(pow(2, nums.size()));
  mid.reserve(nums.size());
  powerSetRec(res, mid, nums, 0);
  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
