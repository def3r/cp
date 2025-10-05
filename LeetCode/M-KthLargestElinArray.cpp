#include "dbg.h"
#include <cstdlib>
#include <utility>
#include <vector>

class Solution {
public:
  Solution() { srand(static_cast<unsigned int>(time(0))); }

  // TLE on leetcode?
  int findKthLargest(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (1) {
      int pivot = l + rand() % (r - l + 1);
      pivot = pivotAndReturn(nums, pivot, l, r);
      if (pivot == k - 1)
        return nums[pivot];
      else if (k - 1 < pivot)
        r = pivot - 1;
      else
        l = pivot + 1;
    }
  }

  int pivotAndReturn(vector<int> &nums, int pivot, int l, int r) {
    swap(nums[pivot], nums[l]);
    int i = l + 1, idx = i;
    for (i = l + 1; i <= r; i++) {
      if (nums[i] > nums[l]) {
        swap(nums[i], nums[idx]);
        idx++;
      }
    }
    swap(nums[l], nums[idx - 1]);
    return idx - 1;
  }

  // Beats 84% in time and 82% in space lol
  int findKthLargestHeapSortLike(vector<int> &nums, int k) {
    int n = nums.size();
    buildMaxHeap(nums);

    int size = n;
    for (int i = 0; i < n && k-- > 1; i++) {
      swap(nums[0], nums[n - 1 - i]);
      maxHeapifyDown(nums, --size, 0);
    }
    return nums[0];
  }

  void buildMaxHeap(vector<int> &nums) {
    int n = nums.size();
    for (int idx = n / 2 - 1; idx >= 0; idx--) {
      maxHeapifyDown(nums, n, idx);
    }
  }

  void maxHeapifyDown(vector<int> &nums, int n, int idx) {
    int leftIdx = 2 * idx + 1;
    int rightIdx = leftIdx + 1;
    int largest = idx;

    if (leftIdx < n && nums[leftIdx] > nums[largest])
      largest = leftIdx;
    if (rightIdx < n && nums[rightIdx] > nums[largest])
      largest = rightIdx;

    if (largest != idx) {
      swap(nums[largest], nums[idx]);
      maxHeapifyDown(nums, n, largest);
    }
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
