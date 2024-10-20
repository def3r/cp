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
    int n;
    ll minCost = INT_MAX;
    map<int, int> fm; // freq map

    cin >> n;
    for (int i = 0; i < n; i++) {
      int el;
      cin >> el;
      fm[el]++;
    }

    // find the cost of every unique val
    for (auto it : fm) {
      ll cost = (ll)it.first * (n - it.second);
      if (cost < minCost) {
        minCost = cost;
      }
    }
    if (minCost > (ll)n)
      minCost = (ll)n; // taking x = 1

    cout << minCost << "\n";
  }

  return 0;
}

/* P o s t  S o l u t i o n  I n t r o s p e c t i o n
 * Wasted nearly an hour just because of type handling.
 * This code, even after being implemented on entirely correct
 * logic, won't pass all test cases.
 *
 * Why so?
 * Well, the constraint.
 *         1 ≤ N ≤ 2×10^5
 * Now, when calculating the cost, multiplication of (int) el
 * is done with remaining num of elements, implying the cost
 * variable could very easily **overflow**
 * demonstration: https://github.com/horrifyingHorse/Segmentation-Fault-Dump/blob/main/dataTypeOverflow.cpp
 *                https://stackoverflow.com/questions/6462439/whats-the-difference-between-long-long-and-long
 *
 * This is exactly what happened and resulted in hidden test
 * case failures.
 */
