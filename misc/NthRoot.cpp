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

int NthRoot(int n, int m) {
  int left, right, mid;
  int nth;

  left = 0, right = m / n;
  while (left <= right) {
    mid = (left + right) / 2;
    nth = std::pow(mid, n);
    if (nth > m) {
      right = mid - 1;
    } else if (nth < m) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  cout << NthRoot(3, 27) << "\t" << NthRoot(4, 69);

  return 0;
}
