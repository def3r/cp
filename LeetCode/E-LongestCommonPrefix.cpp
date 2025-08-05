#include "dbg.h"

string longestCommonPrefix(vector<string> &strs) {
  stringstream ss;
  int minLen = INT_MAX;
  for (string &str : strs) {
    minLen = min(minLen, (int)str.size());
  }
  for (int idx = 0; idx < minLen; idx++) {
    char match = strs[0][idx];
    for (string &str : strs) {
      if (str[idx] != match) {
        return ss.str();
      }
    }
    ss << match;
  }
  return ss.str();
}

#undef dbg_test_fun
int main() {
  vector<string> strs;

#define dbg_test_fun longestCommonPrefix(strs)
  dbg_test_with("fl", strs = {"flower", "flow", "flight"});
  dbg_test_with("", strs = {"dog", "racecar", "car"});

  return EXIT_SUCCESS;
}
