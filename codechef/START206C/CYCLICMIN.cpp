#include "dbg.h"
#include <iostream>

#undef dbg_test_fun
int main() {
  int t;
  int n;

  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v(n, 0);

    int idx = 1;
    if (n & 1) {
      int m = 2;
      for (int i = 1; i <= n; i++) {
        if (m > n) {
          m = 1;
        }
        v[i - 1] = m;
        m += 2;
      }
    } else {
      v[0] = 1;
      for (int i = 1; i < n; i++) {
        v[i] = n - i + 1;
      }
    }
    for (int i : v) {
      cout << i << " ";
    }
    cout << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
