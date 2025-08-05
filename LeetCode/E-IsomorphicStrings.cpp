#include "dbg.h"

bool isIsomorphic(string s, string t) {
  int size = s.size();
  unordered_map<char, char> map;
  unordered_map<char, bool> isMapped;
  for (int idx = 0; idx < size; idx++) {
    if (map.find(s[idx]) != map.end()) {
      if (t[idx] != map[s[idx]]) {
        return false;
      }
    } else {
      if (isMapped[t[idx]]) {
        return false;
      }
      map[s[idx]] = t[idx];
      isMapped[t[idx]] = true;
    }
  }
  return true;
}

#undef dbg_test_fun
int main() {
  string s, t;

#define dbg_test_fun isIsomorphic(s, t)
  dbg_test_with(true, s = "egg", t = "add");
  dbg_test_with(false, s = "foo", t = "bar");
  dbg_test_with(true, s = "paper", t = "title");
  dbg_test_with(false, s = "badc", t = "baba");

  return EXIT_SUCCESS;
}
