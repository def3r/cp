#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
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

int shipWithinDays(vector<int> &weights, int days) {
  int sum = accumulate(weights.begin(), weights.end(), 0);
  if (days == 1) {
    return sum;
  }

  int left, right, mid;
  left = *max_element(weights.begin(), weights.end()), right = sum - 1;
  while (left <= right) {
    mid = (left + right) / 2;

    int estDays = 0, cumW = 0;
    for (int w : weights) {
      if (cumW + w > mid) {
        estDays++;
        cumW = 0;
      }
      cumW += w;
    }

    if (++estDays <= days) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
