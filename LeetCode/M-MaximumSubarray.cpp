#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <vector>
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

// Kadane's Algorithm for Maximum Subarray
// sum = sum < 0 ? 0 : sum
int kadane(vector<int> &nums) {
  int sum = 0, max = INT_MIN;
  for (int num : nums) {
    sum += num;
    // Branchless
    max = sum * (sum > max) + max * (sum <= max);
    sum = sum * (sum < 0);
  }
  return max;
}

// Naive Approach
int maxSubArray(vector<int> &nums) {
  int maxL = INT_MIN, maxR = INT_MIN;
  int indexL = 0, sumL = 0;
  int indexR = 0, sumR = 0;
  int len = nums.size() - 1;

  for (int i = 0; i <= len; i++) {
    sumL = (sumL < 0 && sumL < nums[i]) ? nums[i] : sumL + nums[i];
    sumR = (sumR < 0 && sumR < nums[len - i]) ? nums[len - i]
                                              : sumR + nums[len - i];
    if (sumL > maxL) {
      maxL = sumL;
      indexL = i;
    }
    if (sumR > maxR) {
      maxR = sumR;
      indexR = len - i;
    }
  }
  sumL = 0, maxL = INT_MIN;
  sumR = 0, maxR = INT_MIN;
  do {
    sumL += nums[indexL];
    if (sumL > maxL) {
      maxL = sumL;
    }
  } while (--indexL >= 0);
  do {
    sumR += nums[indexR];
    if (sumR > maxR) {
      maxR = sumR;
    }
  } while (++indexR <= len);
  return max(maxL, maxR);
}

int main() {
  __setup();

  int t;
  cin >> t;

  while (t--) {
  }

  return 0;
}
