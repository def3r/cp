#include "dbg.h"

void recFun(int idx, int toPick, int sum, vector<int> &v,
            vector<vector<int>> &res) {
  if (idx == 0 || toPick == 0 || sum <= 0) {
    if (sum == 0 && toPick == 0) {
      res.push_back(v);
    }
    return;
  }

  v.push_back(idx);
  recFun(idx - 1, toPick - 1, sum - idx, v, res);
  v.pop_back();
  recFun(idx - 1, toPick, sum, v, res);
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<vector<int>> res;
  vector<int> v = {};
  recFun(9, k, n, v, res);
  for (vector<int> list : res) {
    dbg_print_each(list);
  }
  return res;
}

#undef dbg_test_fun
int main() {
  int k, n;

#define dbg_test_fun combinationSum3(k, n)
  k = 3, n = 7;
  dbg_test_fun;

  k = 3, n = 9;
  dbg_test_fun;

  return EXIT_SUCCESS;
}
