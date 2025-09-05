#include "dbg.h"

long long solve(vector<int> &bt) {
  long long exec_t = 0;
  long long total_wt = 0;
  sort(bt.begin(), bt.end());

  for (auto it : bt) {
    total_wt += exec_t;
    exec_t += it;
  }
  return total_wt / bt.size();
}

#undef dbg_test_fun
int main() {
  vector<int> bt = {};

#define dbg_test_fun solve(bt);

  dbg_test_with(4, bt = {4, 1, 3, 7, 2});
  dbg_test_with(2, bt = {1, 2, 3, 4});

  return EXIT_SUCCESS;
}
