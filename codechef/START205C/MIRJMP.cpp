#include "dbg.h"

#undef dbg_test_fun
int main() {
  int t;
  int n, k;

  cin >> t;
  while (t--) {
    cin >> n >> k;

    int steps = 0;
    while (k != n) {
      k = max(k + 1, n - (k - 1));
      steps++;
    }
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
