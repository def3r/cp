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

int findMin(vector<int> &nums) {
  int res;
  int left, right, mid;

  left = 0, right = nums.size() - 1;
  res = nums[(left + right) / 2];
  while (left <= right) {
    mid = (left + right) / 2;
    res = min(nums[mid], res);

    if (nums[right] < res) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return res;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
