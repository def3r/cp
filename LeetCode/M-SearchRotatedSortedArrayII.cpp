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

bool search(vector<int> &nums, int target) {
  int left, right, mid;

  left = 0, right = nums.size() - 1;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[mid] == target) {
      return true;
    }

    if (nums[left] < nums[mid]) {
      if (target >= nums[left] && target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else if (nums[right] > nums[mid]) {
      if (target <= nums[right] && target > nums[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    } else {
      if (nums[mid] == nums[left]) {
        left++;
      }
      if (nums[mid] == nums[right]) {
        right--;
      }
    }
  }

  return false;
}

// 1 4 4 4 4 4
// 4 4 4 4 1 4

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> nums = {1, 3, 5};
  cout << search(nums, 5);

  return 0;
}
