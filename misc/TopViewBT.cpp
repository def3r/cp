#include "dbg.h"
#include <queue>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<int> topView(TreeNode *root) {
    if (root == nullptr)
      return {};
    vector<int> res = {};
    map<int, int> m = {};
    queue<TreeNode *> q = {};
    queue<int> q_col = {};

    q.push(root);
    q_col.push(0);

    int col = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *node = q.front();
        col = q_col.front();
        q.pop(), q_col.pop();

        if (m.find(col) == m.end())
          m[col] = node->data;

        if (node->left)
          q.push(node->left), q_col.push(col - 1);
        if (node->right)
          q.push(node->right), q_col.push(col + 1);
      }
    }

    for (auto it = m.begin(); it != m.end(); ++it)
      res.push_back(it->second);

    return res;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
