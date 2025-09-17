#include "dbg.h"

#undef dbg_test_fun
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a, b;
  cin >> a >> b;
  cout << 180 - (a + b) << endl;

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
