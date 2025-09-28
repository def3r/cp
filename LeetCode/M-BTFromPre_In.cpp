#include "dbg.h"
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

TreeNode *create(vector<int> &preorder, int preStart, int preEnd,
                 map<int, int> &inMap, int inStart, int inEnd) {
  if (preStart > preEnd || inStart > inEnd)
    return nullptr;

  int r = preorder[preStart];
  TreeNode *node = new TreeNode(r);
  int numsLeft = inMap[r] - inStart;

  node->left = create(preorder, preStart + 1, preStart + numsLeft, inMap,
                      inStart, inMap[r] - 1);
  node->right = create(preorder, preStart + numsLeft + 1, preEnd, inMap,
                      inMap[r] + 1, inEnd);

  return node;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
  map<int, int> inMap = {};
  int size = preorder.size();
  for (int i = 0; i < size; i++) {
    inMap[inorder[i]] = i;
  }

  return create(preorder, 0, size - 1, inMap, 0, size - 1);
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
