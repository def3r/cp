#include "dbg.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int pSum(int &pathSum, TreeNode *root) {
  if (root == nullptr)
    return 0;

  int lSum = max(0, pSum(pathSum, root->left));
  int rSum = max(0, pSum(pathSum, root->right));
  int nSum = root->val + lSum + rSum;
  pathSum = max(pathSum, nSum);

  return root->val + max(lSum, rSum);
}

int maxPathSum(TreeNode *root) {
  int res = INT_MIN;
  pSum(res, root);
  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
