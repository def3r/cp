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

int maxProfit(vector<int> &prices) {
  int max = 0, buy = INT_MAX;
  for (auto price : prices) {
    buy = (price < buy) * price + !(price < buy) * buy;
    max = (price - buy > max) * (price - buy) + max * !(price - buy > max);
  }
  return max;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
