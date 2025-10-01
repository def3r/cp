#include "dbg.h"
#include <vector>

#undef dbg_test_fun
int main() {
  int t;
  int n, a;

  while (t--) {
    cin >> n;
    vector<int> v;

    int count[3] = {0, 0, 0};
    while (n--) {
      cin >> a;
      count[a - 1]++;
    }
    int totalPrime = 0;
    totalPrime += count[0] * count[1];
    totalPrime += count[1] * count[2];
    totalPrime += (count[0] - 1) * count[0] / 2;
  }

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
