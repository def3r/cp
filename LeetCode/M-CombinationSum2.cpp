#include "dbg.h"

void rec(int idx, int sum, vector<int> &v, vector<vector<int>> &res,
         vector<int> &candidates) {
  if (sum == 0) {
    res.push_back(v);
    return;
  }
  if (idx == candidates.size() || sum < 0) {
    return;
  }
  v.push_back(candidates[idx]);
  rec(idx + 1, sum - candidates[idx], v, res, candidates);
  v.pop_back();

  for (int i = idx + 1; i < candidates.size(); i++) {
    if (candidates[idx] != candidates[i]) {
      rec(i, sum, v, res, candidates);
      break;
    }
  }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
  vector<vector<int>> res;
  vector<int> v;
  sort(candidates.begin(), candidates.end());

  rec(0, target, v, res, candidates);
  for (vector<int> sol : res) {
    dbg_print_each(sol);
  }
  return res;
}

#undef dbg_test_fun
int main() {
  vector<int> candidates;
  int target;

#define dbg_test_fun combinationSum2(candidates, target)
  candidates = {10, 1, 2, 7, 6, 1, 5}, target = 8;
  dbg_test_fun;
  candidates = {2, 5, 2, 1, 2}, target = 5;
  dbg_test_fun;

  return EXIT_SUCCESS;
}
