#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define fast_io()                                                              \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(NULL);
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()

void __setup() {
  fast_io();

#ifndef ONLINE_JUDGE
  freopen("_input.txt", "r", stdin);
  // freopen("_output.txt", "w", stdout);
#endif
}

int maxRotateFunctionNaive(vector<int>& nums) {
  const int size = nums.size();
  int max = INT_MIN;
  for (int i = 0; i <size; i++) {
    int sum = 0;
    for (int k = 0; k < size; k++) {
      sum += (nums[k] * ((i + k) % size));
    }
    if (sum > max) { max = sum; }
  }
  return max;
}

// Ref: https://leetcode.com/problems/rotate-function/solutions/6891904/c-clear-and-efficient-solution-beats-100/?envType=problem-list-v2&envId=2flbawj1
int maxRotateFunction(vector<int>& nums) {
  int max = INT_MIN, numSum = 0;
  int Fk = 0, i = 0;
  for (auto& num : nums) {
    numSum += num;
    Fk += (i++) * num;
  }

  // F(k) = F(k-1) + numSum - n * nums[n - k]
  int n = nums.size();
  for (i = 1; i < n; i++) {
    Fk = Fk + numSum - n * nums[n - i];
    max = std::max(max, Fk);
  }
  return max;
}

int main() {
  __setup();

  int t;
  cin >> t;

  vector<int> nums;
  int num;
  while (t--) {
    cin >> num;
    nums.push_back(num);
  }
  cout << maxRotateFunction(nums);

  return 0;
}
