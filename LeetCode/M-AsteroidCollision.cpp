#define dbg_expect_1DV
#include "dbg.h"
#include <cmath>
#include <cstdlib>

vector<int> asteroidCollision(vector<int> &asteroids) {
  vector<int> res;

  for (int idx = 0; idx < asteroids.size(); idx++) {
    while (!res.empty() && res.back() > 0 && asteroids[idx] < 0 &&
           abs(asteroids[idx]) > abs(res.back())) {
      res.pop_back();
    }

    if (res.empty() || signbit(res.back()) == signbit(asteroids[idx]) ||
        res.back() < 0) {
      res.push_back(asteroids[idx]);
    } else if (abs(res.back()) == abs(asteroids[idx])) {
      res.pop_back();
    }
  }

  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> asteroids, res;

#define dbg_test_fun asteroidCollision(asteroids)
  dbg_test_with(res, res = {5, 10}, asteroids = {5, 10, -5});
  dbg_test_with(res, res = {}, asteroids = {8, -8});
  dbg_test_with(res, res = {10}, asteroids = {10, 2, -5});
  dbg_test_with(res, res = {-2, -1, 1, 2}, asteroids = {-2, -1, 1, 2});

  return EXIT_SUCCESS;
}
