#include "dbg.h"

int minBitFlips(int start, int goal) {
  // return __builtin_popcount(start ^ goal);

  // Also
  int count = 0;
  int n = start ^ goal;
  while (n > 0) {
    n = n & (n - 1);
    count++;
  }
  return count;
}

#undef dbg_test_fun
int main() {
  int start, goal;

#define dbg_test_fun minBitFlips(start, goal)
  dbg_test_with(3, start = 10, goal = 7);
  dbg_test_with(3, start = 3, goal = 4);

  return EXIT_SUCCESS;
}
