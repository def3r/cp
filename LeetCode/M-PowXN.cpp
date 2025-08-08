#include "dbg.h"

double myPowTail(double accumulator, double x, int n) {
  if (n == 0 || accumulator == 0) {
    return accumulator;
  }
  return myPowTail(accumulator * x, x, n - 1);
}

double myPowTailNeg(double accumulator, double x, int n) {
  if (n == 0 || accumulator == 0) {
    return accumulator;
  }
  return myPowTailNeg(accumulator / x, x, n + 1);
}

double myPow(double x, int n) {
  if (x == 1) {
    return x;
  } else if (x == -1) {
    return (n % 2 == 0) ? 1 : -1;
  }
  return (n > 0) ? myPowTail(1, x, n) : myPowTailNeg(1, x, n);
}

#undef dbg_test_fun
int main() {
  double x;
  int n;

#define dbg_test_fun myPow(x, n)
  dbg_test_with((double)1024, x = 2, n = 10);
  dbg_test_with((double)9.261, x = 2.10000,
                n = 3); // Expected: 9.261; Got: 9.261 ... Crzy
  dbg_test_with((double)0.25, x = 2.00000, n = -2);
  dbg_test_with((double)0, x = 0.00001, n = 2147483647);

  return EXIT_SUCCESS;
}
