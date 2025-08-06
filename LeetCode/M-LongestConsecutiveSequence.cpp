#include "dbg.h"

int longestConsecutiveOptimal(vector<int> &nums) {
  unordered_set<int> numSet(nums.begin(), nums.end());
  int cnt = 0, max = 0;
  for (int num : numSet) {
    if (numSet.find(num - 1) != numSet.end()) {
      continue;
    }
    cnt = 0;
    while (numSet.find(num + 1) != numSet.end()) {
      cnt++;
      num++;
    }
    max = std::max(max, cnt + 1);
  }
  return max;
}

int longestConsecutive(vector<int> &nums) {
  if (nums.size() == 0) {
    return 0;
  }
  unordered_map<int, int> map;
  int max = INT_MIN;

  for (int num : nums) {
    if (map[num] != 0) {
      continue;
    }
    int left = (map[num - 1] != 0) ? num - map[num - 1] : num;
    int right = (map[num + 1] != 0) ? num + map[num + 1] : num;
    map[num] = map[num - 1] + map[num + 1] + 1;
    map[left] = map[num];
    map[right] = map[num];
  }
  for (int num : nums) {
    max = std::max(max, map[num]);
  }

  return max;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun longestConsecutiveOptimal(nums)
  dbg_test_with(6, nums = {1, 5, 3, 4, 2, 6});
  dbg_test_with(4, nums = {100, 4, 200, 1, 3, 2});
  dbg_test_with(9, nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1});
  dbg_test_with(3, nums = {1, 0, 1, 2});

  return EXIT_SUCCESS;
}
