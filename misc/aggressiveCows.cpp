#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
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

int aggressiveCows(vector<int> &nums, int k) {
  sort(nums.begin(), nums.end());

  int left, right, mid;
  left = 1, right = *(nums.end() - 1) - *nums.begin();
  while (left <= right) {
    mid = (left + right) / 2;
    int cowsPlaced = 1;
    int lastPlaced = 0;
    for (int idx = 1; idx < nums.size() && cowsPlaced < k; idx++) {
      if (nums[idx] - nums[lastPlaced] >= mid) {
        cowsPlaced++;
        lastPlaced = idx;
      }
    }
    if (cowsPlaced == k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return right;
}

int main() {
  __setup();

  vector<int> nums = {0, 3, 4, 7, 10, 9};
  int k = 4;

  // vector<int> nums = {4, 2, 1, 3, 6};
  // int k = 2;
  cout << aggressiveCows(nums, k);

  return 0;
}
