#include <bits/stdc++.h>
#include <iostream>
#include <utility>
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

void rotate(vector<vector<int>> &matrix) {
  int n = matrix.size();
  for (int row = 0; row < n; row++) {
    for (int col = row; col < n; col++) {
      swap(matrix[row][col], matrix[col][row]);
    }
  }
  for (int row = 0; row < n; row++) {
    reverse(matrix[row].begin(), matrix[row].end());
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
