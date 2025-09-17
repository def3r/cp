#include "dbg.h"

#undef dbg_test_fun
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  int n, m;

  cin >> t;
  while (t--) {
    cin >> n >> m;
    int wins[2] = {0};
    string s = "";

    cin >> s;
    for (char c : s) {
      wins[c - '0']++;
    }

    if (n & 1 | wins[0] > n / 2 | wins[1] > n / 2) {
      cout << "No" << endl;
      continue;
    }
    cout << "Yes" << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
