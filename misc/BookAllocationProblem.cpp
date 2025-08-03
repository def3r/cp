#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <vector>
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

int findPages(vector<int> &nums, int m) {
  if (nums.size() < m) {
    return -1;
  }
  int left, right, mid;

  left = *max_element(nums.begin(), nums.end());
  right = accumulate(nums.begin(), nums.end(), 0);
  while (left <= right) {
    mid = (left + right) / 2;
    int students = 1;
    int pages = nums[0];
    for (int idx = 1; idx < nums.size(); idx++) {
      if (pages + nums[idx] > mid) {
        students++;
        pages = 0;
      }
      pages += nums[idx];
    }

    if (students <= m) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  __setup();

  // vector<int> nums = {12, 34, 67, 90};
  // int m = 2;

  vector<int> nums = {25, 46, 28, 49, 24};
  int m = 4;

  // vector<int> nums = {1, 2, 3, 4};
  // int m = 1;
  cout << findPages(nums, m);

  return 0;
}
