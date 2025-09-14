#include "dbg.h"
#include <climits>

string minWindow(string s, string t) {
  int minL = INT_MAX, sIdx = -1;
  int n = s.length(), t_n = t.length();
  int count = 0;
  int fmap[256] = {0};
  for (char c : t) {
    fmap[c]++;
  }
  int l = 0, r = 0;

  while (r < n) {
    count += (fmap[s[r]]-- > 0);

    while (count == t_n) {
      if (minL > r - l + 1) {
        minL = r - l + 1;
        sIdx = l;
      }
      count -= (++fmap[s[l++]] > 0);
    }

    r++;
  }

  return (sIdx != -1) ? s.substr(sIdx, minL) : "";
}

string minWindowMY_WAY(string s, string t) {
  unordered_map<char, int> fmap;
  for (char c : t) {
    fmap[c]++;
  }
  int isNotValid = fmap.size();
  int l = 0, r = 0;
  int n = s.length();
  int minL = INT_MAX;
  int minIdx = 0;

  while (r < n) {
    if (fmap.find(s[r]) != fmap.end() && --fmap[s[r]] == 0) {
      isNotValid--;
    }

    while (l <= r && isNotValid == 0) {
      if (minL > r - l + 1) {
        minL = r - l + 1;
        minIdx = l;
      }
      isNotValid = (fmap.find(s[l]) != fmap.end() && ++fmap[s[l]] > 0) ? 1 : 0;
      l++;
    }

    r++;
  }

  return (minL != INT_MAX) ? s.substr(minIdx, minL) : "";
}

#undef dbg_test_fun
int main() {
  string s;
  string t;

#define dbg_test_fun minWindow(s, t)
  dbg_test_with("BANC", s = "ADOBECODEBANC", t = "ABC");
  dbg_test_with("a", s = "a", t = "a");
  dbg_test_with("", s = "a", t = "aa");

  return EXIT_SUCCESS;
}
