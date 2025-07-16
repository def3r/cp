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

  int size, i;
  int n, sum = 0;
  float avg;
  bool valid = false;
  while (t--) {
    cin >> size;
    sum = 0;
    valid = false;
    for (i = 1; i <= size; i++) {
      cin >> n;
      if (valid)
        continue;
      sum += n;
      if ((float(sum) / i) < 40) {
        cout << "No\n";
        valid = true;
      }
    }
    if (!valid) {
      cout << "Yes\n";
    }
  }

  return 0;
}
