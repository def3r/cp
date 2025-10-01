#include "dbg.h"
// Worst framed question ever Stupid ass author (shouldn't say dat)

#undef dbg_test_fun
int main() {
  int t;
  int n;

  cin >> t;
  while (t--) {
    cin >> n;
    cout << max(0, n - 2) << " "
         << ((n == 0) ? 0 : max(0, (n - 2) * (n - 1) / 2));
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
