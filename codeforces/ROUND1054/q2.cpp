#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#undef dbg_test_fun
int main() {
#ifndef ONLINE_JUDGE
  freopen("_input.txt", "r", stdin);
  // freopen("_output.txt", "w", stdout);
#endif

  int t;
  int n, a;

  cin >> t;
  while (t--) {
    cin >> n;

    vector<int> v;
    v.reserve(n);
    while (n--) {
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());

    int maxDiff = 0;
    for (int idx = 0; idx < v.size(); idx += 2)
      maxDiff = max(maxDiff, abs(v[idx] - v[idx + 1]));
    cout << maxDiff << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
