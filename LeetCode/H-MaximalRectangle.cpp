#include "dbg.h"
#include <stack>
#include <vector>

int maxAreaHistogram(vector<int> &ht) {
  int res = 0;
  int n = ht.size();
  int nse = 0, pse = 0;
  stack<int> s;

  for (int idx = 0; idx < n; idx++) {
    while (!s.empty() && ht[s.top()] >= ht[idx]) {
      int top = s.top();
      s.pop();
      pse = s.empty() ? -1 : s.top();
      res = max(res, ht[top] * (idx - pse - 1));
    }
    s.push(idx);
  }

  while (!s.empty()) {
    int top = s.top();
    s.pop();
    pse = s.empty() ? -1 : s.top();
    res = max(res, ht[top] * (n - pse - 1));
  }

  return res;
}

int maximalRectangle(vector<vector<char>> &matrix) {
  int res = 0;
  int rows = matrix.size(), cols = matrix[0].size();
  vector<int> ht(cols, 0);

  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols; col++)
      ht[col] = ((matrix[row][col] - '0') & 1) ? ht[col] + 1 : 0;
    res = max(res, maxAreaHistogram(ht));
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<vector<char>> matrix;

#define dbg_test_fun maximalRectangle(matrix)
  dbg_test_with(6, matrix = {{'1', '0', '1', '0', '0'},
                             {'1', '0', '1', '1', '1'},
                             {'1', '1', '1', '1', '1'},
                             {'1', '0', '0', '1', '0'}});
  dbg_test_with(0, matrix = {{'0'}});
  dbg_test_with(1, matrix = {{'1'}});

  return EXIT_SUCCESS;
}
