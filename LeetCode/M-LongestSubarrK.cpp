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

int maxSubarrayLength(vector<int> &nums, int k) {
  unordered_map<int, int> map;
  long from = 0, max = 0, i;
  for (i = 0; i < nums.size(); i++) {
    if (++map[nums[i]] > k) {
      if (i - from > max) {
        max = i - from;
      }

      do {
        map[nums[from]]--;
      } while (from < i && nums[from++] != nums[i]);
    }
  }
  if (i - from > max) {
    max = i - from;
  }
  return max;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
    int k, n, temp;
    vector<int> arr;
    cin >> k >> n;
    while (n--) {
      cin >> temp;
      arr.emplace_back(temp);
    }
    cout << maxSubarrayLength(arr, k);
  }

  return 0;
}
