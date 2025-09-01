#include "dbg.h"
#include <unordered_map>

bool lemonadeChange(vector<int> &bills) {
  unordered_map<int, int> m;

  for (int bill : bills) {
    switch (bill) {
    case 5:
      m[5]++;
      break;
    case 10:
      m[10]++;
      if (m[5]-- <= 0)
        return false;
      break;
    case 20:
      if (m[10] >= 1 && m[5] >= 1)
        m[10]--, m[5]--;
      else if (m[5] >= 3)
        m[5] -= 3;
      else
        return false;
      break;
    }
  }

  return true;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
