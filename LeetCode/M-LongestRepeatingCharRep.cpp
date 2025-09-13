#include "dbg.h"

int characterReplacement(string s, int k) {
  int maxLen = 0;
  int l = 0, r = 0;
  int n = s.length();
  int maxFq = 0;
  int m[26] = {};

  for (r = 0; r < n; r++) {
    maxFq = max(maxFq, ++m[s[r] - 'A']);
    if (r - l + 1 - maxFq > k) {
      m[s[l] - 'A']--;
      l++;
    }
    if (r - l + 1 - maxFq <= k) {
      maxLen = max(maxLen, r - l + 1);
    }
  }

  return maxLen;
}

#undef dbg_test_fun
int main() {
  string s;
  int k;

#define dbg_test_fun characterReplacement(s, k)
  dbg_test_with(4, s = "ABAB", k = 2);
  dbg_test_with(4, s = "AABABBA", k = 1);
  dbg_test_with(2, s = "BDDEC", k = 0);
  dbg_test_with(2, s = "AECAD", k = 1);

  return EXIT_SUCCESS;
}
