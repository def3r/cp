#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
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

vector<int> leaders(vector<int> nums) {
  vector<int> list;
  int max = INT_MIN;
  for (int idx = nums.size() - 1; idx >= 0; idx--) {
    if (nums[idx] > max) {
      max = nums[idx];
      list.push_back(max);
    }
  }
  reverse(list.begin(), list.end());
  return list;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> in = {1, 2, 5, 3, 1, 2};
  auto res = leaders(in);
  for (int num : res) {
    cout << num << "\t";
  }
  cout << "\n";

  return 0;
}
