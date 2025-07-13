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

// Moore's Majority Voting Algorithm
// Single Pass O(n)
// If the array compulsarily contains a Majority Element,
// element w/ freq > floor(n/2), then the last element is
// the Majority Element.
// If not, verify it.
int majorityElement(vector<int> &nums) {
  int count = 0;
  int element = nums[0];
  for (auto &num : nums) {
    if (element == num) {
      count++;
    } else if (count == 0) {
      element = num;
    } else {
      count--;
    }
  }
  return element;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
