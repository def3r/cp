#include "dbg.h"
#include <vector>

void combinationRec(int idx, int sum, vector<int> &numVec,
                    vector<vector<int>> &res, vector<int> &candidates) {
  if (sum == 0) {
    res.push_back(numVec);
    return;
  }
  if (idx < 0 || sum < 0) {
    return;
  }
  numVec.push_back(candidates[idx]);
  combinationRec(idx, sum - candidates[idx], numVec, res, candidates);
  numVec.pop_back();
  combinationRec(idx - 1, sum, numVec, res, candidates);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
  vector<vector<int>> res = {};
  vector<int> numVec = {};
  combinationRec(candidates.size() - 1, target, numVec, res, candidates);
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> candidates;
  int target;

#define dbg_test_fun combinationSum(candidates, target)
  candidates = {2, 3, 6, 7}, target = 7;
  dbg_test_fun;

  candidates = {2, 3, 5}, target = 8;
  dbg_test_fun;

  candidates = {2}, target = 1;
  dbg_test_fun;

  return EXIT_SUCCESS;
}
