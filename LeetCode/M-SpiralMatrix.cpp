#include <bits/stdc++.h>
#include <iostream>
#include <ostream>
#include <pthread.h>
using namespace std;

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

void __setup() {
  fast_io();

#ifndef ONLINE_JUDGE
  freopen("_input.txt", "r", stdin);
  // freopen("_output.txt", "w", stdout);
#endif
}

vector<int> spiralOrder(vector<vector<int>> &matrix) {
  int rowSize = matrix.size(), colSize = matrix[0].size();
  vector<int> res;
  res.reserve(rowSize * colSize);
  int rowRem = rowSize, colRem = colSize;

  int row = 0, col = 0;
  int rowDir = 1, colDir = 1;
  while (rowRem != 0 || colRem != 0) {
    int travRow = rowRem, travCol = colRem;
    while (travCol--) {
      res.push_back(matrix[row][col]);
      col += colDir;
    }
    col -= colDir;
    colDir *= -1;
    rowRem = max(rowRem - 1, 0);
    travRow = rowRem;
    row += rowDir;
    if (res.size() == rowSize * colSize) {
      break;
    }

    while (travRow--) {
      res.push_back(matrix[row][col]);
      row += rowDir;
    }
    row -= rowDir;
    rowDir *= -1;
    colRem = max(colRem - 1, 0);
    col += colDir;
  }

  return res;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (auto num : spiralOrder(matrix)) {
    cout << num << " ";
  }
  cout << "\n";

  return 0;
}
