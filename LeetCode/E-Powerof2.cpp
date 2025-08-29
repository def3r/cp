#include "dbg.h"

bool isPowerOfTwo(int n) { return (n <= 0) ? false : (n & (n - 1)) == 0; }

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
