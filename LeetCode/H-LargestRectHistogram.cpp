#include "dbg.h"
#include <stack>
#include <vector>

int largestRectangleAreaOptimized(vector<int> &heights) {
  int res = 0;
  int n = heights.size();
  int pse = -1;
  stack<int> s;

  for (int idx = 0; idx < n; idx++) {
    while (!s.empty() && heights[s.top()] >= heights[idx]) {
      int top = s.top();
      s.pop();
      pse = (s.empty()) ? -1 : s.top();
      res = max(res, heights[top] * (idx - pse - 1));
    }
    s.push(idx);
  }
  while (!s.empty()) {
    int top = s.top();
    s.pop();
    pse = (s.empty()) ? -1 : s.top();
    res = max(res, heights[top] * (n - pse - 1));
  }

  return res;
}

vector<int> NSE(vector<int> &heights, int n) {
  vector<int> res(n);
  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && heights[s.top()] >= heights[i])
      s.pop();
    res[i] = (s.empty()) ? n : s.top();
    s.push(i);
  }

  return res;
}

vector<int> PSE(vector<int> &heights, int n) {
  vector<int> res(n);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && heights[s.top()] >= heights[i])
      s.pop();
    res[i] = (s.empty()) ? -1 : s.top();
    s.push(i);
  }

  return res;
}

int largestRectangleArea(vector<int> &heights) {
  int res = 0;
  int n = heights.size();
  vector<int> nse = NSE(heights, n), pse = PSE(heights, n);
  dbg_print_each(nse);
  dbg_print_each(pse);

  for (int idx = 0; idx < n; idx++) {
    int f = nse[idx] - pse[idx] - 1;
    res = max(res, heights[idx] * f);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> heights;

#define dbg_test_fun largestRectangleAreaOptimized(heights)
  dbg_test_with(10, heights = {2, 1, 5, 6, 2, 3});
  dbg_test_with(6, heights = {2, 1, 5, 1, 2, 3});

  return EXIT_SUCCESS;
}
