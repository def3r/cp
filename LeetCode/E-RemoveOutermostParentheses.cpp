#include "dbg.h"

string removeOuterParentheses(string s) {
  int openPar = 0;
  int op = 0;
  stringstream ss;
  for (auto it = s.begin(); it != s.end(); ++it) {
    switch (*it) {
    case '(': {
      if (openPar++ >= 1) {
        ss << *it;
      }
      break;
    }
    case ')': {
      if (--openPar >= 1) {
        ss << *it;
      }
      break;
    }
    }
  }
  return ss.str();
}

#undef dbg_test_fun
int main() {
  string s;

#define dbg_test_fun removeOuterParentheses(s)
  dbg_test_with("()()()", s = "(()())(())");
  dbg_test_with("()()()()(())", s = "(()())(())(()(()))");
  dbg_test_with("", s = "()()");

  return EXIT_SUCCESS;
}
