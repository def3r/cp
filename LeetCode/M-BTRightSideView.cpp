#include "dbg.h"
#include <queue>
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

vector<int> rightSideView(TreeNode *root) {
  vector<int> res = {};
  if (root == nullptr)
    return res;

  map<int, int> m = {};
  queue<pair<TreeNode *, int>> q = {};
  q.push({root, 0});

  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      TreeNode *node = q.front().first;
      int row = q.front().second;
      q.pop();

      m[row] = node->val;

      if (node->left)
        q.push({node->left, row + 1});
      if (node->right)
        q.push({node->right, row + 1});
    }
  }
  for (auto it = m.begin(); it != m.end(); ++it)
    res.push_back(it->second);

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
