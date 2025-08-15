#include "dbg.h"

bool isValidPos(int row, int col, vector<int> &mp) {
  for (int i = 0; i < row; i++) {
    if (mp[i] == col || abs(mp[i] - col) == abs(i - row)) {
      return false;
    }
  }
  return true;
}

void recFun(int row, int n, vector<int> &mp, vector<vector<string>> &res) {
  if (row >= n) {
    vector<string> v;
    v.reserve(n);
    for (int r = 0; r < n; r++) {
      char buf[n + 1];
      memset(buf, '.', n);
      buf[n] = '\0';
      buf[mp[r]] = 'Q';
      v.push_back(buf);
    }
    res.push_back(v);
  }

  for (int i = 0; i < n; i++) {
    if (!isValidPos(row, i, mp)) {
      continue;
    }
    mp.push_back(i);
    recFun(row + 1, n, mp, res);
    mp.pop_back();
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<vector<string>> res = {};
  vector<int> mp = {};
  mp.reserve(n);

  recFun(0, n, mp, res);
  for (auto &list : res) {
    dbg_print_each(list);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  int n;

#define dbg_test_fun solveNQueens(n)
  n = 4;
  dbg_test_fun;

  return EXIT_SUCCESS;
}
