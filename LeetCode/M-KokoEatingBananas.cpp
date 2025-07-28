#include <bits/stdc++.h>
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

int minEatingSpeedOptimal(vector<int> &piles, int h) {
  int left, right;
  double mid;
  int totalH = 0;

  left = 1;
  right = *max_element(piles.begin(), piles.end());
  while (left <= right) {
    mid = (left + right) / 2; // NOLINT
    totalH = 0;
    for (int amt : piles) {
      totalH += ceil(amt / mid);
    }
    if (totalH <= h) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int minEatingSpeed(vector<int> &piles, int h) {
  int left, right;
  double mid;
  int hDone = 0, sol = 0;
  int idx, size = piles.size();

  left = 1;
  right = *max_element(piles.begin(), piles.end());
  if (size == h) {
    return right;
  }
  while (left <= right) {
    mid = (left + right) / 2; // NOLINT
    for (idx = 0, hDone = 0; idx < size && hDone < h; idx++) {
      hDone += ceil(piles[idx] / mid);
    }
    if (hDone > h) {
      left = mid + 1;
    } else if (hDone == h) {
      sol = mid;
      if (idx == size) {
        if (right == mid) {
          break;
        }
        right = mid;
      } else {
        left = mid + 1;
      }
    } else {
      sol = mid;
      right = mid - 1;
    }
  }
  return sol;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  vector<int> piles = {30, 11, 23, 4, 20};
  int h = 6;

  // vector<int> piles = {1000000000};
  // int h = 2;

  // cout << minEatingSpeed(piles, h) << "\n";
  cout << minEatingSpeedOptimal(piles, h);

  return 0;
}
