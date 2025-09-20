#include "dbg.h"

int trap(vector<int> &height) {
  int amt = 0;
  int l = 0, r = height.size() - 1;
  int leftMax = height[l], rightMax = height[r];

  while (l < r) {
    if (height[l] <= height[r]) {
      leftMax = max(leftMax, height[l]);
      amt += leftMax - height[l++];
    } else {
      rightMax = max(rightMax, height[r]);
      amt += rightMax - height[r--];
    }
  }

  return amt;
}

int trapSuffixPrefixMax(vector<int> &height) {
  int amt = 0;
  int n = height.size();
  vector<int> suffixMax(n, 0), prefixMax(n, 0);

  prefixMax[0] = height[0];
  suffixMax[n - 1] = height[n - 1];
  for (int i = 1; i < n; i++) {
    prefixMax[i] = max(prefixMax[i - 1], height[i]);
    suffixMax[n - i - 1] = max(suffixMax[n - i], height[n - i - 1]);
  }

  for (int i = 0; i < n; i++) {
    if (height[i] < prefixMax[i] && height[i] < suffixMax[i])
      amt += min(prefixMax[i], suffixMax[i]) - height[i];
  }

  return amt;
}

// Brute Force
int trapBrute(vector<int> &height) {
  int n = height.size();
  int amt = 0;

  for (int i = 0; i < n; i++) {
    int ht = height[i];
    while (ht != 0) {
      int j = i + 1;

      while (j < n && height[j] < ht)
        j++;
      ht--;
      if (j == i + 1)
        break;
      if (j == n)
        continue;
      amt += max((j - i - 1), 0);
    }
  }

  return amt;
}

#undef dbg_test_fun
int main() {
  vector<int> height;

#define dbg_test_fun trap(height)
  dbg_test_with(6, height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
  dbg_test_with(9, height = {4, 2, 0, 3, 2, 5});
  dbg_test_with(568, height = {930, 444, 906, 800, 906});

  return EXIT_SUCCESS;
}
