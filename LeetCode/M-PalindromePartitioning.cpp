#include "dbg.h"

bool isPalindrome(const string &s, int b_idx, int e_idx) {
  // int size = s.length();
  // if (!(0 <= b_idx && b_idx < size) || !(0 <= e_idx && e_idx < size)) {
  //   return false;
  // } else if (e_idx < b_idx) {
  //   return false;
  // }
  while (b_idx <= e_idx) {
    if (s[b_idx++] != s[e_idx--]) {
      return false;
    }
  }
  return true;
}

void recFun(int idx, vector<string> &v, string &s,
            vector<vector<string>> &res) {
  if (idx >= s.length()) {
    res.push_back(v);
    return;
  }
  v.push_back(s.substr(idx, 1));
  recFun(idx + 1, v, s, res);
  v.pop_back();
  for (int l = 1; l < s.length() - idx; l++) {
    if (isPalindrome(s, idx, idx + l)) {
      v.push_back(s.substr(idx, l + 1));
      recFun(idx + l + 1, v, s, res);
      v.pop_back();
    }
  }
}

vector<vector<string>> partition(string s) {
  vector<vector<string>> res;
  vector<string> v;
  recFun(0, v, s, res);
  for (vector<string> list : res) {
    dbg_print_each(list);
  }
  return res;
}

#undef dbg_test_fun
int main() {
  string s;

#define dbg_test_fun partition(s)
  s = "aabaa";
  dbg_test_fun;

  return EXIT_SUCCESS;
}
