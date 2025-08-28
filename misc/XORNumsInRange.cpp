#include "dbg.h"

int xor1ton(int n) {
  switch (n % 4) {
  case 0:
    return n;
  case 1:
    return 1;
  case 2:
    return n + 1;
  case 3:
    return 0;
  }
  // unreachable
}

int findRangeXOR(int l, int r) { return xor1ton(l - 1) ^ xor1ton(r); }

#undef dbg_test_fun
int main() {
  int l, r;

#define dbg_test_fun findRangeXOR(l, r)
  dbg_test_with(2, l = 3, r = 5);
  dbg_test_with(0, l = 1, r = 3);
  dbg_test_with(11, l = 4, r = 10);

  return EXIT_SUCCESS;
}
