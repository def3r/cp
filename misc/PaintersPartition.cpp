#include "dbg.h"

int paint(int A, int B, vector<int> &C) {
  int left, right, mid;
  left = *max_element(C.begin(), C.end());
  right = accumulate(C.begin(), C.end(), 0);
  while (left <= right) {
    mid = (left + right) / 2;
    int painters = 1;
    uint32_t len = 0;
    for (int idx = 0; idx < C.size(); idx++) {
      if (len + C[idx] > mid) {
        painters++;
        len = 0;
      }
      len += C[idx];
    }
    if (painters > A) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return (left * B) % 10000003;
}

#undef dbg_test_fun
int main() {
  int a, b;
  vector<int> c;

#define dbg_test_fun paint(a, b, c);
  dbg_test_with(11, a = 10; b = 1; c = {1, 8, 11, 3});
  dbg_test_with(50, a = 2; b = 5; c = {1, 10});

  return EXIT_SUCCESS;
}
