#define dbg_expect_1DV
#include "dbg.h"

class StockSpanner {
public:
  StockSpanner() {}

  int next(int price) {
    int res = 0;
    int idx = arr.size();
    while (!s.empty() && arr[s.top()] <= price) {
      s.pop();
    }
    res = s.empty() ? idx + 1 : idx - s.top();
    arr.push_back(price);
    s.push(idx);
    return res;
  }

private:
  vector<int> arr = {};
  stack<int> s = {};
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

vector<int> stockSpan(vector<int> arr, int n) {
  vector<int> res(n, 0);
  stack<int> s;

  for (int idx = 0; idx < n; idx++) {
    while (!s.empty() && arr[s.top()] <= arr[idx]) {
      s.pop();
    }
    res[idx] = s.empty() ? idx + 1 : idx - s.top();
    s.push(idx);
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> arr, res;
  int n;

#define dbg_test_fun stockSpan(arr, n)
  dbg_test_with(res, res = {1, 1, 1, 2, 3, 5, 6}, n = 7,
                arr = {120, 100, 60, 80, 90, 110, 115});

  return EXIT_SUCCESS;
}
