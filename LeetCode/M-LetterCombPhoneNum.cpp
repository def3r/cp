#include "dbg.h"
#include <cstring>

// TC -> O(4**N)
void recFun(int idx, int v_idx, char *v, string &digits, vector<string> &res) {
  if (idx >= digits.length()) {
    v[v_idx] = '\0';
    if (strcmp(v, "") != 0) {
      res.push_back(v);
    }
    return;
  }

  int digit = digits[idx] - '0';
  int limit = (digit == 7 || digit == 9) ? 4 : 3;
  int isGt7 = (digit > 7);
  for (int i = 0; i < limit; i++) {
    v[v_idx] = 'a' + (digit - 2) * 3 + i + isGt7;
    recFun(idx + 1, v_idx + 1, v, digits, res);
  }
}

vector<string> letterCombinations(string digits) {
  vector<string> res;
  const int v_size = 3 * 3 * 3 * 3;
  char v[v_size];
  v[v_size - 1] = '\0';
  // 'a' + (digit - 2) * 3
  recFun(0, 0, v, digits, res);
  dbg_print_each(res);
  return res;
}

#undef dbg_test_fun
int main() {
  string digits;

#define dbg_test_fun letterCombinations(digits)
  digits = "9";
  dbg_test_fun;

  return EXIT_SUCCESS;
}
