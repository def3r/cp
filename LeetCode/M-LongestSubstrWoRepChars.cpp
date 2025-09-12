#include "dbg.h"
#include <unordered_map>

int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> m;
  int maxLen = 0;

  int l = 0, r = 0;
  for (r = 0; r < s.length(); r++) {
    if (m.find(s[r]) != m.end())
      l = max(m[s[r]] + 1, l);
    maxLen = max(maxLen, r - l + 1);
    m[s[r]] = r;
  }

  return maxLen;
}

#undef dbg_test_fun
int main() {
  string s;

#define dbg_test_fun lengthOfLongestSubstring(s)

  return EXIT_SUCCESS;
}
