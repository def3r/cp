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

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
    int n, h; // eNemies, strengtH
    vector<int> a;

    cin >> n >> h;
    while (n--) {
      int i;
      cin >> i;
      a.push_back(i);
    }
    make_heap(a.begin(), a.end());
    sort_heap(a.begin(), a.end());

    int cumSum = 0; // cumulative Sum
    int X = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
      cumSum += a[i];
      if (cumSum >= h) {
        X = a[i];
        break;
      }
    }
    cout << X << "\n";
  }

  return 0;
}
