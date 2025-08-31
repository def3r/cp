#include "dbg.h"

int findContentChildren(vector<int> &g, vector<int> &s) {
  int res = 0;
  sort(g.begin(), g.end());
  sort(s.begin(), s.end());

  for (int it_s = s.size() - 1, it_g = g.size() - 1; it_s >= 0 && it_g >= 0;
       it_g--) {
    if (s[it_s] >= g[it_g])
      res++, it_s--;
  }
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> g, s;

#define dbg_test_fun findContentChildren(g, s);

  dbg_test_with(1, g = {1, 2, 3}, s = {1, 1});
  dbg_test_with(2, g = {1, 2}, s = {1, 2, 3});

  return EXIT_SUCCESS;
}
