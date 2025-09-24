#include "dbg.h"

#undef dbg_test_fun
int main() {
  int t;
  int x, y;

  cin >> t;
  while (t--) {
    cin >> x >> y;
    int score = 0;
    int pack = (x + y) / 3;
    score = pack + min(y, pack);
    cout << score << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
