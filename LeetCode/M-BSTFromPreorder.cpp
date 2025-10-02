#include "dbg.h"
#include <climits>
#include <vector>

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
  TreeNode *buildTree(vector<int> &po, int max) {
    if (idx >= po.size() || po[idx] > max)
      return nullptr;
    TreeNode *node = new TreeNode(po[idx++]);
    node->left = buildTree(po, node->val);
    node->right = buildTree(po, max);
    return node;
  }

  TreeNode *bstFromPreorder(vector<int> &preorder) {
    return buildTree(preorder, INT_MAX);
  }

  int idx = 0;
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
