#include <algorithm>
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

int smallestDivisor(vector<int> &nums, int threshold) {
  int left, right, mid;

  left = 1, right = *max_element(nums.begin(), nums.end());
  while (left <= right) {
    mid = (left + right) / 2;

    int res = 0;
    for (int num : nums) {
      res += (ceil(num / (double)mid));
    }

    if (res <= threshold) {
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
