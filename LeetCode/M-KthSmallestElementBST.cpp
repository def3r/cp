#include "dbg.h"
#include <climits>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int inorder(TreeNode *root, int k) {
    if (root == nullptr)
      return k;
    k = inorder(root->left, k);
    if (--k == 0)
      res = root->val;
    if (k <= 0)
      return k;
    return inorder(root->right, k);
  }

  int kthSmallest(TreeNode *root, int k) {
    res = 0;
    inorder(root, k);
    return res;
  }

  int res = 0;
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
