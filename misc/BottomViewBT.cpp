#include "dbg.h"
#include <queue>
#include <vector>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<int> bottomView(TreeNode *root) {
    vector<int> res = {};
    if (root == nullptr)
      return res;

    map<int, int> m = {};
    queue<pair<TreeNode *, int>> q = {};
    q.push({root, 0});

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *top = q.front().first;
        int col = q.front().second;
        q.pop();

        m[col] = top->data;

        if (top->left)
          q.push({top->left, col - 1});
        if (top->right)
          q.push({top->right, col + 1});
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
