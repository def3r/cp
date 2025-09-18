#include <stack>
#include <unordered_map>
#define dbg_expect_1DV
#include "dbg.h"

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
  vector<int> res = {};
  res.reserve(nums1.size());

  unordered_map<int, int> m;
  stack<int> s;
  for (int i = nums2.size() - 1; i >= 0; i--) {
    while (!s.empty() && s.top() <= nums2[i]) {
      s.pop();
    }
    m[nums2[i]] = (s.empty()) ? -1 : s.top();
    s.push(nums2[i]);
  }

  for (int num : nums1) {
    res.push_back(m[num]);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> nums1, nums2, res;

#define dbg_test_fun nextGreaterElement(nums1, nums2)
  dbg_test_with(res, res = {-1, 3, -1}, nums1 = {4, 1, 2},
                nums2 = {1, 3, 4, 2});

  return EXIT_SUCCESS;
}
