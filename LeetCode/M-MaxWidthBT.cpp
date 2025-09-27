#include "dbg.h"
#include <algorithm>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

int widthOfBinaryTree(TreeNode *root) {
  int res = 0;
  if (root == nullptr)
    return res;

  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  while (!q.empty()) {
    int size = q.size();
    int minCol = 0, maxCol = 0;
    int firstCol = q.front().second;
    while (size--) {
      TreeNode *front = q.front().first;
      int idx = q.front().second - firstCol;
      q.pop();

      minCol = min(idx, minCol);
      maxCol = max(idx, maxCol);

      // left child -> 2i + 1
      // right child = 2i + 2
      if (front->left)
        q.push({front->left, 2 * (idx - 1) + 1});
      if (front->right)
        q.push({front->right, 2 * (idx - 1) + 2});
    }
    res = max(res, maxCol - minCol + 1);
  }

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
