#include "dbg.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lowestCommonAncestorBetter(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (root == nullptr)
    return root;

  if (p == root || q == root)
    return root;

  TreeNode *left = lowestCommonAncestorBetter(root->left, p, q);
  TreeNode *right = lowestCommonAncestorBetter(root->right, p, q);

  if (left != nullptr && right != nullptr)
    return root;

  return left != nullptr ? left : right;
}

int lca(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode **node) {
  if (root == nullptr)
    return 0;

  int count = 0, rcount = 0;
  count = lca(root->left, p, q, node);
  if (count == 2)
    return 2;

  rcount = lca(root->right, p, q, node);
  if (rcount == 2)
    return 2;

  count += rcount;
  if (p == root)
    count++;
  if (q == root)
    count++;

  if (count == 2) {
    *node = root;
    return 2;
  }

  return count;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
  TreeNode *res = nullptr;
  lca(root, p, q, &res);
  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
