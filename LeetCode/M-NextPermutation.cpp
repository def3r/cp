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

void nextPermutation(vector<int> &nums) {
  int len = nums.size() - 1;
  if (len == 0) {
    return;
  }
  if (nums[len] > nums[len - 1]) {
    swap(nums[len], nums[len - 1]);
    return;
  }

  int idx = len - 1;
  while (idx > 0 && nums[idx] <= nums[idx - 1]) {
    idx--;
  }
  if (idx == 0) {
    reverse(nums.begin(), nums.end());
    return;
  }
  idx = (idx > 0) * (idx - 1);

  for (int i = len; i > idx; i--) {
    // redundant: && nums[i] < nums[closest]
    if (nums[i] > nums[idx]) {
      swap(nums[idx], nums[i]);
      break;
    }
  }
  reverse(nums.begin() + idx + 1, nums.end());
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
