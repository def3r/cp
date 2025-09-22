#include "dbg.h"

int celebrityBetter(vector<vector<int>> &M) {
  int n = M.size();
  int top = 0, bottom = n - 1;

  while (top < bottom) {
    if (M[top][bottom])
      top++;
    else if (M[bottom][top])
      bottom--;
    else
      top++, bottom--;
  }

  int i = 0;
  while (i < n && (M[top][i] == 0 && (M[i][top] == 1 || i == top)))
    i++;
  if (i < n)
    return -1;

  return top;
}

int celebrity(vector<vector<int>> &M) {
  int row = 0, col = 0, check = 0;
  int n = M.size();

  for (row = 0; row < n; row++) {
    col = 0;
    while (col < n && M[row][col] == 0)
      col++;
    if (col != n)
      continue;

    check = 0;
    while (check < n && (M[check][row] == 1 || check == row))
      check++;
    if (check == n)
      return row;
  }

  return -1;
}

#undef dbg_test_fun
int main() {
  vector<vector<int>> M;

#define dbg_test_fun celebrityBetter(M)
  dbg_test_with(1,
                M = {{0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}});
  dbg_test_with(-1, M = {{0, 1}, {1, 0}});
  dbg_test_with(0, M = {{0}});
  dbg_test_with(-1,
                M = {{0, 1, 1, 1}, {0, 0, 0, 0}, {1, 0, 0, 1}, {1, 0, 0, 0}});

  return EXIT_SUCCESS;
}
