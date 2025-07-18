#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
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

int subarraySum(vector<int> &nums, int k) {
  int count = 0, preSum = 0;
  unordered_map<int, int> preSumMap;
  preSumMap[0]++;
  for (int num : nums) {
    preSum += num;
    count += preSumMap[preSum - k];
    preSumMap[preSum]++;
  }
  return count;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }
  vector<int> nums = {1, 2, 3, -3, 6};
  cout << subarraySum(nums, 3);

  return 0;
}
