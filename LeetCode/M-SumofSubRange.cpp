#include "dbg.h"

vector<int> NSE(vector<int> &nums, int n) {
  vector<int> res(n, n);
  stack<int> s;

  for (int idx = n - 1; idx >= 0; idx--) {
    while (!s.empty() && nums[s.top()] >= nums[idx]) {
      s.pop();
    }
    res[idx] = (!s.empty()) ? s.top() : n;
    s.push(idx);
  }

  return res;
}

vector<int> NGE(vector<int> &nums, int n) {
  vector<int> res(n, n);
  stack<int> s;

  for (int idx = n - 1; idx >= 0; idx--) {
    while (!s.empty() && nums[s.top()] <= nums[idx]) {
      s.pop();
    }
    res[idx] = (!s.empty()) ? s.top() : n;
    s.push(idx);
  }

  return res;
}

vector<int> PSEE(vector<int> &nums, int n) {
  vector<int> res(n, -1);
  stack<int> s;

  for (int idx = 0; idx < n; idx++) {
    while (!s.empty() && nums[s.top()] > nums[idx]) {
      s.pop();
    }
    res[idx] = (!s.empty()) ? s.top() : -1;
    s.push(idx);
  }

  return res;
}

vector<int> PGEE(vector<int> &nums, int n) {
  vector<int> res(n, -1);
  stack<int> s;

  for (int idx = 0; idx < n; idx++) {
    while (!s.empty() && nums[s.top()] < nums[idx]) {
      s.pop();
    }
    res[idx] = (!s.empty()) ? s.top() : -1;
    s.push(idx);
  }

  return res;
}

long long subArrayRanges(vector<int> &nums) {
  long long sum = 0;
  int n = nums.size();
  vector<int> nse = NSE(nums, n), nge = NGE(nums, n);
  vector<int> pse = PSEE(nums, n), pge = PGEE(nums, n);

  for (int idx = 0; idx < n; idx++) {
    int left = idx - pse[idx];
    int right = nse[idx] - idx;
    long long freq_s = right * left;

    left = idx - pge[idx];
    right = nge[idx] - idx;
    long long freq_l = right * left;
    sum = sum + nums[idx] * (freq_l - freq_s);
  }

  return sum;
}

#undef dbg_test_fun
int main() {
  vector<int> nums;

#define dbg_test_fun subArrayRanges(nums)
  dbg_test_with(4, nums = {1, 2, 3});
  dbg_test_with(4, nums = {1, 3, 3});

  return EXIT_SUCCESS;
}
