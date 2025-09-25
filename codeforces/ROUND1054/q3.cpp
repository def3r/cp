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
  int n, k, a;

  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> m(k, 0);
    int ltK = k;
    int eqK = 0;

    while (n--) {
      cin >> a;
      if (a < k) {
        ltK = ltK - (m[a]++ == 0);
      }
      eqK += (a == k);
    }
    cout << max(eqK, ltK) << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
