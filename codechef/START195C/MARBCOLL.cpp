#include <bits/stdc++.h>
#include <iostream>
#include <set>
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

  int n, m, item;
  while (t--) {
    set<int> possesion;
    cin >> n >> m;
    while (n--) {
      cin >> item;
      possesion.insert(item);
    }
    cout << m - possesion.size() << "\n";
  }

  return 0;
}
