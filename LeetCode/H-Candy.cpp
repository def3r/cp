#include "dbg.h"

int candyOptimal(vector<int> &ratings) {
  int sum = 1;
  int peak = 0, low = 0;

  int idx = 1;
  int n = ratings.size();
  while (idx < n) {
    // flat
    if (ratings[idx] == ratings[idx - 1]) {
      sum++, idx++;
      continue;
    }

    // inc slope
    peak = 1;
    while (idx < n && ratings[idx - 1] < ratings[idx]) {
      peak++, sum += peak, idx++;
    }

    // dec slope
    low = 1;
    while (idx < n && ratings[idx - 1] > ratings[idx]) {
      sum += low, low++, idx++;
    }

    if (low > peak) {
      sum += (low - peak);
    }
  }

  return sum;
}

int candy(vector<int> &ratings) {
  vector<int> candies(ratings.size(), 1);

  // Left to right
  for (int idx = 0; idx < ratings.size() - 1; idx++) {
    if (ratings[idx] > ratings[idx + 1]) {
      candies[idx] = (candies[idx] > candies[idx + 1]) ? candies[idx]
                                                       : candies[idx + 1] + 1;
    } else if (ratings[idx] < ratings[idx + 1]) {
      candies[idx + 1] = (candies[idx + 1] > candies[idx]) ? candies[idx + 1]
                                                           : candies[idx] + 1;
    }
  }

  // Right to left
  for (int idx = ratings.size() - 1; idx > 0; idx--) {
    if (ratings[idx] > ratings[idx - 1]) {
      candies[idx] = (candies[idx] > candies[idx - 1]) ? candies[idx]
                                                       : candies[idx - 1] + 1;
    } else if (ratings[idx] < ratings[idx - 1]) {
      candies[idx - 1] = (candies[idx - 1] > candies[idx]) ? candies[idx - 1]
                                                           : candies[idx] + 1;
    }
  }
  return accumulate(candies.begin(), candies.end(), 0);
}

#undef dbg_test_fun
int main() {
  vector<int> ratings;

#define dbg_test_fun candyOptimal(ratings)
  dbg_test_with(12, ratings = {5, 0, 4, 2, 7, 6, 3});

  return EXIT_SUCCESS;
}
