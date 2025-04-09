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

int reverseInteger(int x) {
  if (x == 0)
    return 0;

  int rev = 0;
  while (x / 10 || x % 10) {
    if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
      return 0;
    }

    rev = rev * 10 + x % 10;
    x = x / 10;
  }

  return rev;
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
    int x;
    cin >> x;
    cout << reverseInteger(x) << "\n";
  }

  return 0;
}
