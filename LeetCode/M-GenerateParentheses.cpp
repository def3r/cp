#include "dbg.h"
#include <vector>

void genParRec(vector<string> &v, char *s, int slen, int pO, int n) {
  if (slen == 2 * n) {
    v.push_back(s);
    return;
  }
  if (pO < n) {
    s[slen] = '(';
    genParRec(v, s, slen + 1, pO + 1, n);
    if (!(slen - pO < pO)) {
      return;
    }
  }
  s[slen] = ')';
  genParRec(v, s, slen + 1, pO, n);
}

vector<string> generateParenthesis(int n) {
  vector<string> v;
  char *bfr = new char[n * 2 + 1];
  bfr[2 * n] = '\0';
  bfr[0] = '(';
  genParRec(v, bfr, 1, 1, n);
  dbg_print_each(v);
  return v;
}

#undef dbg_test_fun
int main() {
  int n;

#define dbg_test_fun generateParenthesis(n)
  n = 3;
  dbg_test_fun;

  return EXIT_SUCCESS;
}
