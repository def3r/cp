#include "dbg.h"
#include <vector>

int noOfGasStationReq(long double dist, vector<int> &arr) {
  int count = 0;
  for (int idx = 1; idx < arr.size(); idx++) {
    auto diff = arr[idx] - arr[idx - 1];
    int c = diff / dist;
    if (c * dist == diff) {
      c--;
    }
    count += c;
  }
  return count;
}

long double minimiseMaxDistanceOptimal(vector<int> &arr, int k) {
  long double left, right, mid;
  left = 0;
  right = 0;
  for (int idx = 0; idx < arr.size() - 1; idx++) {
    right = max(right, (long double)arr[idx + 1] - arr[idx]);
  }

  while (right - left > pow(10, -6)) {
    mid = (left + right) / 2;
    if (noOfGasStationReq(mid, arr) > k) {
      left = mid;
    } else {
      right = mid;
    }
  }

  return right;
}

// ULTRA NOOB APPROACH, Completely ASS time complexity
// O(N + log N * (N +  K * N + N)) What on Earth is this abomination of time
// complexity = O(N * N * logN)
// Space Complexity: O(N)
long double minimiseMaxDistance(vector<int> &arr, int k) {
  vector<long double> dist;
  dist.reserve(arr.size() - 1);
  long double left, right, mid;
  long double ans = 0;
  left = 0;
  right = 0;
  for (int idx = 0; idx < arr.size() - 1; idx++) {
    dist.push_back(arr[idx + 1] - arr[idx]);
    right = max(right, (long double)arr[idx + 1] - arr[idx]);
  }

  while (left <= right) {
    mid = (left + right) / 2;
    int placed = 0;
    vector<long double> distCpy = dist;
    while (placed < k) {
      auto max = max_element(distCpy.begin(), distCpy.end());
      if (*max > mid) {
        *max -= mid;
        placed++;
      } else {
        break;
      }
    }
    long double max = *max_element(distCpy.begin(), distCpy.end());
    if (max > mid) {
      left = floor(mid + 1);
    } else {
      ans = mid;
      right = ceil(mid - 1);
    }
  }
  return ans;
}

#undef dbg_test_fun
int main() {
  vector<int> arr;
  int k;

#define dbg_test_fun minimiseMaxDistanceOptimal(arr, k)
  dbg_test_with(0.5, arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; k = 9);
  dbg_test_with(1, arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; k = 1);
  dbg_test_with(3, arr = {1, 2, 3, 4, 10}; k = 1);

  return EXIT_SUCCESS;
}
