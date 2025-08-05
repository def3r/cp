#include "dbg.h"

int kthElement(vector<int> &a, vector<int> &b, int k) {
  int n1 = a.size(), n2 = b.size();
  int left, right;
  int mid1, mid2;

  left = 0, right = k;
  while (left <= right) {
    mid1 = (left + right) / 2;
    mid2 = (k - mid1);
    int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
    int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];
    int r1 = (mid1 == n1) ? INT_MAX : a[mid1];
    int r2 = (mid2 == n2) ? INT_MAX : b[mid2];

    if (l1 <= r2 && l2 <= r1) {
      return max(l1, l2);
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
  vector<int> a, b;
  int k;

#define dbg_test_fun kthElement(a, b, k)
  dbg_test_with(6, a = {2, 3, 6, 7, 9}, b = {1, 4, 8, 10}, k = 5);
  dbg_test_with(256, a = {100, 112, 256, 349, 770},
                b = {72, 86, 113, 119, 265, 445, 892}, k = 7);

  return EXIT_SUCCESS;
}
