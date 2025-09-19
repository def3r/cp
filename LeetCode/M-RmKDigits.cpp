#include "dbg.h"

string removeKdigits(string num, int k) {
  string res;

  for (char c : num) {
    while (k > 0 && !res.empty() && res.back() > c) {
      res.pop_back();
      k--;
    }
    if (res.empty() && c == '0')
      continue;
    res.push_back(c);
  }

  while (k > 0 && !res.empty()) {
    res.pop_back();
    k--;
  }

  return res == "" ? "0" : res;
}

#undef dbg_test_fun
int main() {
  string num;
  int k;

#define dbg_test_fun removeKdigits(num, k)
  dbg_test_with("1219", num = "1432219", k = 3);
  dbg_test_with("200", num = "10200", k = 1);
  dbg_test_with("21", num = "1002991", k = 3);
  dbg_test_with("1234", num = "123456", k = 2);
  dbg_test_with("0", num = "10", k = 2);

  return EXIT_SUCCESS;
}
