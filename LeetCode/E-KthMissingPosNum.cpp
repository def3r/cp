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

int findKthPositiveOptimal(vector<int> &arr, int k) {
  int left, right, mid;
  left = 0, right = arr.size() - 1;
  while (left <= right) {
    mid = (left + right) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return (k + right + 1);
}

int findKthPositive(vector<int> &arr, int k) {
  int count = 1, idx = 0, len = arr.size() - 1;
  for (count = 1; count <= 5000; count++) {
    while (count < arr[idx]) {
      if (--k == 0)
        return count;
      count++;
    };
    if (count == arr[idx]) {
      idx = min(len, idx + 1);
    } else if (count > arr[idx]) {
      k--;
    }
    if (k == 0) {
      break;
    }
  }
  return count;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }
  // vector<int> arr = {1, 2, 3, 4};
  vector<int> arr = {2, 3, 4, 7, 11};
  int k = 5;
  cout << findKthPositiveOptimal(arr, k);

  return 0;
}
