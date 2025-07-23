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

int main() {
  __setup();

  int t;
  cin >> t;

  int n, c;
  while (t--) {
    cin >> n >> c;
    int temp;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      a.push_back(temp);
    }
    sort(a.begin(), a.end());

    if (c > a.back()) {
      cout << 0 << "\n";
      continue;
    }
    int idx = 0;
    while (a[idx] < c) {
      idx++;
    }

    int extra = 0;
    while (idx < a.size()) {
      if (idx == 0) {
        extra = a[idx] - c + 1;
        idx++;
        continue;
      }
      if (a[idx] == c + extra) {
        extra++;
        idx++;
      } else if (a[idx] < c + extra) {
        idx++;
      } else {
        break;
      }
    }
    cout << extra << "\n";
  }

  return 0;
}
