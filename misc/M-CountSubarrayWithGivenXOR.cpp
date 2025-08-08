#include "dbg.h"
#include <vector>

int subarraysWithXorK(vector<int> &nums, int k) {
  unordered_map<int, int> map;
  int count = 0;
  int xr = 0;

  map[0] = 1;
  for (int num : nums) {
    xr ^= num;
    if (map.find(xr ^ k) != map.end()) {
      count += map[xr ^ k];
    }
    map[xr]++;
  }
  return count;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;
  int k;

#define dbg_test_fun subarraysWithXorK(nums, k)
  dbg_test_with(4, nums = {4, 2, 2, 6, 4}, k = 6);
  dbg_test_with(2, nums = {5, 6, 7, 8, 9}, k = 5);

  return EXIT_SUCCESS;
}
