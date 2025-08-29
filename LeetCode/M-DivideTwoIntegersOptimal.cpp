#include "dbg.h"
#include <climits>

int divideOptimal(long dividend, long divisor) {
  if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
  }
  int q = 0;
  bool sign = (dividend >> 31) ^ (divisor >> 31);
  long long n = abs(dividend), d = abs(divisor);
  while (n >= d) {
    int count = 0;

    while (n >= (d << (count + 1)))
      count++;

    q += (1 << count);
    n -= (d << count);
  }

  return (sign == false) ? q : (~q + 1);
}

#undef dbg_test_fun
int main() {
  int dd, ds;

#define dbg_test_fun divideOptimal(dd, ds)
  dbg_test_with(3, dd = 10, ds = 3);
  dbg_test_with(5, dd = 10, ds = 2);
  dbg_test_with(5, dd = 20, ds = 4);
  dbg_test_with(2, dd = 7, ds = 3);
  dbg_test_with(-2, dd = 7, ds = -3);
  dbg_test_with(INT_MIN, dd = INT_MIN, ds = 1);
  dbg_test_with(-2147483648, dd = -2147483648, ds = 1);

  return EXIT_SUCCESS;
}
