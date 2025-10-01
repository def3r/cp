#include "dbg.h"
#include <functional>
#include <vector>

#undef dbg_test_fun
int main() {
  int t;
  int k, n, a;

  cin >> t;
  while (t--) {
    cin >> k >> n;
    vector<int> c(n);
    while (n--) {
      cin >> a;
      c.push_back(a);
    }
    sort(c.begin(), c.end(), greater<int>());
    int cost = 0;
    while (k--) {
      cost += c[k];
    }
    cout << cost << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
