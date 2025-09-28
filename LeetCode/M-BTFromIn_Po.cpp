#include "dbg.h"
#include <unordered_map>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *create(vector<int> &postorder, int poStart, int poEnd,
                 unordered_map<int, int> &inMap, int inStart, int inEnd) {
  if (poStart > poEnd || inStart > inEnd)
    return 0;

  int root = postorder[poEnd];
  TreeNode *node = new TreeNode(root);
  int numsRight = inEnd - inMap[root];

  node->right = create(postorder, poEnd - numsRight, poEnd - 1, inMap,
                       inMap[root] + 1, inEnd);
  node->left = create(postorder, poStart, poEnd - numsRight - 1, inMap, inStart,
                      inMap[root] - 1);

  return node;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
  unordered_map<int, int> inMap = {};
  int size = postorder.size();
  for (int idx = 0; idx < size; idx++) {
    inMap[inorder[idx]] = idx;
  }
  return create(postorder, 0, size - 1, inMap, 0, size - 1);
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
