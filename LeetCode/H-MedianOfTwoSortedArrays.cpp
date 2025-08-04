#include "dbg.h"
#include <vector>

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
  int m = nums1.size(), n = nums2.size();
  if (m > n) {
    return findMedianSortedArrays(nums2, nums1);
  }
  int partition = (m + n + 1) / 2;
  int left, right;

  left = 0, right = m;
  while (left <= right) {
    int mid1 = (left + right) / 2;
    int mid2 = partition - mid1;
    int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
    int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
    int r1 = (mid1 >= m) ? INT_MAX : nums1[mid1];
    int r2 = (mid2 >= n) ? INT_MAX : nums2[mid2];

    if (l1 <= r2 && l2 <= r1) {
      return ((m + n) % 2 == 1) ? max(l1, l2)
                                : ((double)(max(l1, l2) + min(r1, r2)) / 2);
    } else if (l1 > r2) {
      right = mid1 - 1;
    } else {
      left = mid1 + 1;
    }
  }
  return 0;
}

#undef dbg_test_fun
int main() {
  vector<int> nums1, nums2;

#define dbg_test_fun findMedianSortedArrays(nums1, nums2)
  dbg_test_with((double)2, nums1 = {1, 3}; nums2 = {2});
  dbg_test_with((double)2.5, nums1 = {1, 2}; nums2 = {3, 4});

  return EXIT_SUCCESS;
}
