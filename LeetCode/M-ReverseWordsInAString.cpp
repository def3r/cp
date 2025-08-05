#include "dbg.h"

string reverseWords(string s) {
  stringstream ss;
  string_view sv = s;
  int start = -1;

  for (int idx = s.size() - 1; idx >= 0; idx--) {
    if (sv[idx] == ' ') {
      if (start != -1) {
        ss << sv.substr(idx + 1, (start - idx)) << " ";
      }
      start = -1;
    } else if (sv[idx] != ' ' && start == -1) {
      start = idx;
    }
  }
  if (start != -1) {
    ss << sv.substr(0, start + 1);
    return ss.str();
  }

  string res = ss.str();
  return res.substr(0, res.size() - 1);
}

#undef dbg_test_fun
int main() {
  string s;

#define dbg_test_fun reverseWords(s)
  dbg_test_with("blue is sky the", s = "the sky is blue");
  dbg_test_with("world hello", s = "  hello world  ");
  dbg_test_with("example good a", s = "a good   example");

  return EXIT_SUCCESS;
}
