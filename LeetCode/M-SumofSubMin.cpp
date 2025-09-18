#include "dbg.h"
#include <cmath>
#include <stack>
#include <vector>

vector<int> NSE(vector<int> &arr, int n) {
  vector<int> res(n, n);
  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && arr[s.top()] >= arr[i]) {
      s.pop();
    }
    res[i] = (!s.empty()) ? s.top() : n;
    s.push(i);
  }

  return res;
}

vector<int> PSEE(vector<int> &arr, int n) {
  vector<int> res(n, -1);
  stack<int> s;

  for (int i = 0; i < n; i++) {
    while (!s.empty() && arr[s.top()] > arr[i]) {
      s.pop();
    }
    res[i] = (!s.empty()) ? s.top() : -1;
    s.push(i);
  }

  return res;
}

int sumSubarrayMins(vector<int> &arr) {
  long long sum = 0;
  int n = arr.size();
  vector<int> nse = NSE(arr, n);
  vector<int> pse = PSEE(arr, n);

  int mod = 1e9 + 7;
  for (int idx = 0; idx < n; idx++) {
    int left = idx - pse[idx];
    int right = nse[idx] - idx;
    long long freq = left * right * 1LL;
    int val = (freq * arr[idx]) % mod;
    sum = (sum + val) % mod;
  }

  return sum;
}

#undef dbg_test_fun
int main() {
  vector<int> arr;

#define dbg_test_fun sumSubarrayMins(arr)
  dbg_test_with(17, arr = {3, 1, 2, 4});

  return EXIT_SUCCESS;
}
