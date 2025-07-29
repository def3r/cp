#include <algorithm>
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

int minDays(vector<int> &bloomDay, int m, int k) {
  long int size = bloomDay.size();
  long long adj = static_cast<long>(m) * static_cast<long>(k);
  int max = *max_element(bloomDay.begin(), bloomDay.end());
  if (adj > size) {
    return -1;
  } else if (adj == size) {
    return max;
  }

  int left, right, mid;
  left = 1, right = max;
  while (left <= right) {
    mid = (left + right) / 2;
    int count = 0, posM = 0;
    for (int day : bloomDay) {
      if (day <= mid) {
        count++;
      } else {
        posM += count / k;
        count = 0;
      }
    }
    posM += count / k;

    if (posM >= m) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};
  int m = 2;
  int k = 3;
  cout << minDays(bloomDay, m, k);

  return 0;
}
