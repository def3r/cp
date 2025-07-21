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

vector<int> getFloorAndCeil(vector<int> nums, int x) {
  vector<int> res;
  res.reserve(2);

  int left, right, mid;
  int bound = -1;
  left = 0, right = nums.size();
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] <= x) {
      bound = nums[mid];
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  res.push_back(bound);

  bound = -1;
  left = 0, right = nums.size();
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] >= x) {
      bound = nums[mid];
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  res.push_back(bound);
  return res;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> nums = {3, 4, 4, 7, 8, 10};
  vector<int> res = getFloorAndCeil(nums, 8);
  cout << res[0] << "\t" << res[1];

  return 0;
}
