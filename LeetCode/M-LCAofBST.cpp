#include "dbg.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *lowestCommonAncestorOptimal(TreeNode *root, TreeNode *p,
                                        TreeNode *q) {
    if (root == nullptr)
      return root;

    if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestorOptimal(root->right, p, q);
    if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestorOptimal(root->left, p, q);

    return root;
  }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr)
      return nullptr;
    if (root->val == p->val || root->val == q->val)
      return root;

    TreeNode *left = 0, *right = 0;
    if (root->val > p->val || root->val > q->val)
      left = lowestCommonAncestor(root->left, p, q);

    if (root->val < p->val || root->val < q->val)
      right = lowestCommonAncestor(root->right, p, q);

    return (left && right) ? root : (left) ? left : right;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
