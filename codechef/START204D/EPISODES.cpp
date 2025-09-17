#include "dbg.h"

#undef dbg_test_fun
int main() {
  int t;
  int n, k;

  cin >> t;
  while (t--) {
    cin >> n >> k;
    int total = n * k;

    cout << (total / 60) << " " << (total % 60) << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
