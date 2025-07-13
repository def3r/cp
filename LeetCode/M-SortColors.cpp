#include <bits/stdc++.h>
#include <iostream>
#include <strings.h>
#include <utility>
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

// Dutch National Flag Algorithm
// Single pass O(n)
// 0..low-1     -> 0
// low..mid-1   -> 1
// high+1..n-1  -> 2
void dutchNationalFlagAlgo(vector<int> &nums) {
  vector<int>::iterator low, mid, high;
  low = nums.begin();
  mid = nums.begin();
  high = nums.end() - 1;
  while (mid <= high) {
    switch (*mid) {
    case 0:
      iter_swap(mid++, low++);
      break;
    case 1:
      mid++;
      break;
    case 2:
      iter_swap(mid, high--);
      break;
    }
  }
}

void sortColors(vector<int> &nums) {
  int index = 0;
  vector<int> freq = {0, 0, 0};
  for (int num : nums) {
    freq[num]++;
  }
  for (int i = 0; i < 3; i++) {
    for (; freq[i]; freq[i]--) {
      nums[index++] = i;
    }
  }
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
