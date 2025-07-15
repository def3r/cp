#include <bits/stdc++.h>
#include <deque>
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

vector<int> optimalApproach(vector<int> &nums) {
  vector<int> res;
  res.assign(nums.size(), 0);
  int pos = 0, neg = 1;
  for (int num : nums) {
    if (num > 0) {
      res[pos] = num;
      pos += 2;
    } else {
      res[neg] = num;
      neg += 2;
    }
  }
  return res;
}

// Naive Approach
vector<int> rearrangeArray(vector<int> &nums) {
  int size = nums.size();
  vector<int> neg, pos;
  neg.reserve(size / 2);
  pos.reserve(size / 2);
  for (int num : nums) {
    if (num < 0) {
      neg.push_back(num);
    } else {
      pos.push_back(num);
    }
  }
  for (int idx = 0; idx < size / 2; idx++) {
    nums[idx * 2] = pos[idx];
    nums[idx * 2 + 1] = neg[idx];
  }
  return nums;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
