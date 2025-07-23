#include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
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

  int n;
  while (t--) {
    vector<int> tastiness, sugar;
    cin >> n;

    int temp;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      tastiness.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
      cin >> temp;
      sugar.push_back(temp);
    }

    unordered_map<int, int> m;
    for (int idx = 0; idx < n; idx++) {
      if (tastiness[idx] < 0) {
        continue;
      }
      m[sugar[idx]] += tastiness[idx];
    }
    sort(sugar.begin(), sugar.end());

    int max = 0;
    int sum = 0;
    for (int idx = 0; idx < n; idx++) {
      int s = sugar[idx];
      if (idx > 0 && s == sugar[idx - 1]) {
        continue;
      }
      sum += m[s];
      max = std::max(sum - s, max);
    }
    cout << max << "\n";
  }

  return 0;
}
