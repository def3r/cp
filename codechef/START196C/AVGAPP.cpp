#include <bits/stdc++.h>
#include <climits>
#include <cmath>
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

int main() {
  __setup();

  int t;
  cin >> t;

  int n, k;
  while (t--) {
    cin >> n >> k;
    int min1 = INT_MAX, min2 = INT_MAX;

    int temp;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      sum += temp;
      if (temp < min1) {
        min2 = min1;
        min1 = temp;
      } else if (temp < min2) {
        min2 = temp;
      }
    }

    sum += min1 - int((min1 / pow(2, k))) + int((min2 / pow(2, k))) +
           (1 - int(1 / pow(2, k)));
    cout << sum << "\n";
  }

  return 0;
}
