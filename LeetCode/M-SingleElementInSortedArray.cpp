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

int singleNonDuplicate(vector<int> &nums) {
  int left, right, mid;
  int len = nums.size() - 1;

  left = 0, right = len;
  while (left <= right) {
    mid = (left + right) / 2;
    if (nums[max(mid - 1, 0)] != nums[mid] &&
        nums[min(mid + 1, len)] != nums[mid]) {
      break;
    }

    if ((mid % 2) == 0) {
      if (nums[max(mid - 1, 0)] == nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    } else {
      if (nums[mid] == nums[min(mid + 1, len)]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }

  return nums[mid];
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> nums = {3, 3, 7, 7, 10, 11, 11};
  cout << singleNonDuplicate(nums);

  return 0;
}
