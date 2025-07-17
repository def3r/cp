#include <bits/stdc++.h>
#include <iostream>
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

// Optimal Approach
// T.C: O(N**2)
// S.C: O(1)
void optimal(vector<vector<int>> &matrix) {
  int col0 = matrix[0][0];
  int rowSize = matrix.size(), colSize = matrix[0].size();
  for (int row = 0; row < rowSize; row++) {
    for (int col = 0; col < colSize; col++) {
      if (!matrix[row][col]) {
        matrix[row][0] = 0;
        if (col == 0) {
          col0 = 0;
        } else {
          matrix[0][col] = 0;
        }
      }
    }
  }

  for (int row = 1; row < rowSize; row++) {
    for (int col = 1; col < colSize; col++) {
      if (matrix[row][col]) {
        if (!matrix[0][col] || !matrix[row][0]) {
          matrix[row][col] = 0;
        }
      }
    }
  }

  if (!matrix[0][0]) {
    matrix[0].assign(colSize, 0);
  }
  if (!col0) {
    for (int row = 0; row < rowSize; row++) {
      matrix[row][0] = 0;
    }
  }
}

// Single Pass but
// T.C: O(N**3)
// S.C: O(N)
void setZeroes(vector<vector<int>> &matrix) {
  int colSize = matrix[0].size();
  int rowSize = matrix.size();
  bool resetRow = false;
  unordered_set<int> colSet;
  colSet.reserve(colSize);

  for (int row = 0; row < rowSize; row++) {
    for (int col = 0; col < colSize; col++) {
      if (matrix[row][col] == 0) {
        for (int rowUp = row - 1; rowUp >= 0; rowUp--) {
          matrix[rowUp][col] = 0;
        }
        colSet.insert(col);
        resetRow = true;
      }
    }
    for (int col : colSet) {
      matrix[row][col] = 0;
    }
    if (resetRow) {
      resetRow = false;
      for (int col = 0; col < colSize; col++) {
        matrix[row][col] = 0;
      }
    }
  }
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
