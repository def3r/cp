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

long long floorSqrt(long long n) {
  long long left, right, mid;
  long long sqr;

  left = 0, right = n / 2;
  while (left <= right) {
    mid = (left + right) / 2;
    sqr = mid * mid;

    if (sqr > n) {
      right = mid - 1;
    } else if (sqr < n) {
      left = mid + 1;
    } else {
      return mid;
    }
  }
  return right;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  cout << floorSqrt(36) << "\t" << floorSqrt(122);

  return 0;
}
