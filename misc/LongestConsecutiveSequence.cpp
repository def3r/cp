#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <unordered_set>
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

int optimal(vector<int> &nums) {
  int l = 0, max = 0;

  unordered_set<int> set;
  set.reserve(nums.size());
  for (int num : nums) {
    set.insert(num);
  }

  for (int num : set) {
    if (set.find(num - 1) != set.end()) {
      continue;
    }
    l = 0;
    while (set.find(num++) != set.end()) {
      l++;
    }
    max = (l > max) * l + !(l > max) * max;
  }
  return max;
}

int longestConsecutive(vector<int> &nums) {
  int l = 0, max = 0;
  int size = nums.size();

  sort(nums.begin(), nums.end());
  for (int idx = 0; idx < size - 1; idx++) {
    if (nums[idx + 1] == nums[idx] + 1) {
      l++;
    } else if (nums[idx + 1] == nums[idx]) {
    } else {
      max = (l > max) * l + !(l > max) * max;
    }
  }
  max = (l > max) * l + !(l > max) * max;
  return (max > 0) ? max + 1 : 0;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> nums = {100, 4, 200, 1, 3, 2};
  cout << optimal(nums);

  return 0;
}
