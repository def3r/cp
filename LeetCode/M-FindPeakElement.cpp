#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
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

// Works but what the hell??
// not O(log n) ?? {or is it?}
int findPeak(vector<int> &nums, int left, int right) {
  if (left > right) {
    return -1;
  }
  int mid = (left + right) / 2;
  if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) {
    return mid;
  }
  int leftFind = findPeak(nums, left, mid - 1);
  if (leftFind != -1) {
    return leftFind;
  }
  int rightFind = findPeak(nums, mid + 1, right);
  if (rightFind != -1) {
    return rightFind;
  }
  return -1;
}

int findPeakElement(vector<int> &nums) {
  if (nums.size() == 1) {
    return 0;
  }
  if (nums[0] > nums[1]) {
    return 0;
  }
  int len = nums.size() - 1;
  if (nums[len - 1] < nums[len]) {
    return len;
  }

  return findPeak(nums, 1, len - 1);
}

int findPeakElementOptimal(vector<int> &nums) {
  if (nums.size() == 1) {
    return 0;
  }
  if (nums[0] > nums[1]) {
    return 0;
  }
  int len = nums.size() - 1;
  if (nums[len - 1] < nums[len]) {
    return len;
  }

  int left, right, mid;
  left = 1, right = len - 1;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) {
      return mid;
    }
    if (nums[mid - 1] < nums[mid]) {
      left = mid + 1;
    } else {
      right = mid - 1;
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

  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  cout << findPeakElementOptimal(nums);

  return 0;
}
