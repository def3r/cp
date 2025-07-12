#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
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

vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> map;
  int size = nums.size(), rem;
  for (int i = 0; i < size; i++) {
    map[nums[i]] = i;
  }
  for (int i = 0; i < size; i++) {
    rem = target - nums[i];
    if (map.find(rem) != map.end() && i != map[rem]) {
      return {i, map[rem]};
    }
  }
  return {};
}

bool twoSumOptimal(vector<int> &nums, int target) {
  sort(nums.begin(), nums.end());
  int left = 0, right = nums.size() - 1;
  while (left < right) {
    int sum = nums[left] + nums[right];
    if (sum == target) {
      return true;
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
  return false;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
