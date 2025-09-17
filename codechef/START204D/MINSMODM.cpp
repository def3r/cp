#include "dbg.h"

#undef dbg_test_fun
int main() {
  int t;
  int n, m;
  long long sum = 0, minSum = 0;

  cin >> t;
  while (t--) {
    cin >> n >> m;
    int temp = 0;
    unordered_map<int, int> fmap;
    sum = 0;

    int t_n = n;
    while (t_n--) {
      cin >> temp;
      sum += temp;
      fmap[m - temp]++;
    }

    minSum = sum;
    m = m - 1;
    for (int i = 1; i <= m; i++) {
      sum = sum - m * fmap[i] + n - fmap[i];
      minSum = min(sum, minSum);
    }
    cout << minSum << endl;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
