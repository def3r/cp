#include "dbg.h"

#undef dbg_test_fun
int main() {
  int t;
  int n, a;

  cin >> t;
  while (t--) {
    // index: even -> 0, odd -> 1
    bool b[2] = {0, 0}, twos[2] = {0, 0};
    int idx = 0;
    cin >> n;
    while (n--) {
      cin >> a;
      if ((a & 1))
        b[idx % 2] = true;
      else
        twos[idx % 2] = true;
      idx++;
    }
    bool sol = true;
    if (twos[0]) {
      sol &= b[0];
    }
    if (twos[1]) {
      sol &= b[1];
    }
    cout << ((sol) ? "NO" : "YES") << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
