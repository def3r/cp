#include "dbg.h"
#include <algorithm>

int totalFruit(vector<int> &fruits) {
  int f[2] = {-1, -1}, fIdx[2] = {-1, -1};
  int l = 0, r = 0;
  int n = fruits.size();
  int maxF = 0;
  int idx = 0;

  for (r = 0; r < n; r++) {
    if (fruits[r] != f[0] && fruits[r] != f[1]) {
      idx = fIdx[1] < fIdx[0];
      l = max(fIdx[idx] + 1, 0);
      f[idx] = fruits[r];
    }
    fIdx[f[1] == fruits[r]] = r;
    maxF = max(maxF, r - l + 1);
  }

  return maxF;
}

#undef dbg_test_fun
int main() {
  vector<int> fruits;

#define dbg_test_fun totalFruit(fruits)
  dbg_test_with(3, fruits = {1, 2, 1});
  dbg_test_with(3, fruits = {0, 1, 2, 2});
  dbg_test_with(4, fruits = {1, 2, 3, 2, 2});
  dbg_test_with(37, fruits = {23, 27, 27, 23, 23, 27, 27, 27, 23, 23, 27,
                              27, 27, 23, 23, 23, 23, 23, 27, 23, 23, 27,
                              23, 23, 27, 23, 27, 23, 23, 23, 27, 27, 23,
                              23, 27, 23, 23, 19, 7,  35, 33, 5,  14, 37,
                              20, 40, 30, 16, 17, 22, 49, 19, 42});

  return EXIT_SUCCESS;
}
