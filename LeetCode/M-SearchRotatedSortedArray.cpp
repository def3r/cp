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

int search(vector<int> &nums, int target) {
  int left, right, mid;

  left = 0, right = nums.size() - 1;
  while (left <= right) {
    mid = (left + right) / 2;

    if (nums[right] < nums[mid] && target <= nums[right]) {
      left = mid + 1;
    } else if (nums[left] > nums[mid] && target >= nums[left]) {
      right = mid - 1;
    } else {
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] == target) {
        return mid;
      }
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
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << search(nums, 3);

  return 0;
}
