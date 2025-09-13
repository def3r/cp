#include "dbg.h"

int kDistinctChar(string &s, int k) {
  int maxLen = 0;
  int l = 0, r = 0;
  int n = s.length();
  unordered_map<char, int> m;

  for (r = 0; r < n; r++) {
    m[s[r]] = r;
    if (m.size() > k) {
      if (m[s[l]] == l)
        m.erase(s[l]);
      l++;
    }
    if (m.size() <= k) {
      maxLen = max(maxLen, r - l + 1);
    }
  }

  return maxLen;
}

#undef dbg_test_fun
int main() {
  string s;
  int k;

#define dbg_test_fun kDistinctChar(s, k)
  dbg_test_with(6, s = "aababbcaacc", k = 2);

  return EXIT_SUCCESS;
}
