#include "dbg.h"

int maxScore(vector<int> &cardPoints, int k) {
  int maxSum = 0, sum = 0;
  int n = cardPoints.size();
  int r = n - 1, l = n - k;
  sum = accumulate(cardPoints.begin() + l, cardPoints.end(), 0);
  maxSum = sum;

  while (k--) {
    sum -= cardPoints[l];
    l = (l + 1) % n;
    r = (r + 1) % n;
    sum += cardPoints[r];
    maxSum = max(maxSum, sum);
  }

  return maxSum;
}

#undef dbg_test_fun
int main() {
  vector<int> cardPoints;
  int k;

#define dbg_test_fun maxScore(cardPoints, k)
  dbg_test_with(12, k = 3, cardPoints = {1, 2, 3, 4, 5, 6, 1});
  dbg_test_with(232, k = 4, cardPoints = {11, 49, 100, 20, 86, 29, 72});

  return EXIT_SUCCESS;
}
