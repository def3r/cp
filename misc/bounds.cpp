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

int upperBound(vector<int> &nums, int x) {
  int left, right, mid;
  int size = nums.size();
  int res = size;

  left = 0, right = res - 1;
  while (left < right) {
    mid = (left + right) / 2;
    if (nums[mid] < x) {
      res = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return res;
}

int lowerBound(vector<int> &nums, int x) {
  int left, right, mid;
  int size = nums.size();
  int res = size;

  left = 0, right = res - 1;
  while (left < right) {
    mid = (left + right) / 2;
    if (nums[mid] >= x) {
      res = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
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

  vector<int> nums = {1, 2, 2, 3};
  cout << lowerBound(nums, 2);

  return 0;
}
