#include "dbg.h"

int numberOfSubstrings(string s) {
  int count = 0;
  int valid = 0;
  int l = 0, r = 0;
  int fmap[3] = {0};
  int n = s.length();

  while (r < n) {
    if (fmap[s[r] - 'a']++ == 0) {
      valid++;
    }
    while (valid == 3) {
      count += n - r;
      if (--fmap[s[l++] - 'a'] == 0) {
        valid--;
      }
    }
    r++;
  }

  return count;
}

#undef dbg_test_fun
int main() {
  string s;

#define dbg_test_fun numberOfSubstrings(s)
  dbg_test_with(10, s = "abcabc");
  dbg_test_with(3, s = "aaacb");
  dbg_test_with(1, s = "abc");

  return EXIT_SUCCESS;
}
