#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
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

int splitArray(vector<int> &nums, int k) {
  int left, right, mid;
  int size = nums.size();
  if (size < k) {
    return -1;
  }

  left = *max_element(nums.begin(), nums.end());
  right = accumulate(nums.begin(), nums.end(), 0);
  while (left <= right) {
    mid = (left + right) / 2;
    uint32_t sum = 0;
    int count = 1;
    for (int idx = 0; idx < size; idx++) {
      if (sum + nums[idx] > mid) {
        count++;
        sum = 0;
      }
      sum += nums[idx];
    }
    if (count > k) {
      left = mid + 1;
    } else {
      right = mid - 1;
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
