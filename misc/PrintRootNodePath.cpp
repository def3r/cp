#include "dbg.h"
#include <vector>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  void rec(vector<vector<int>> &res, vector<int> &v, TreeNode *root) {
    if (root == nullptr)
      return;
    v.push_back(root->data);
    if (root->left == nullptr && root->right == nullptr && !v.empty())
      res.push_back(v);
    rec(res, v, root->left);
    rec(res, v, root->right);
    v.pop_back();
  }

  vector<vector<int>> allRootToLeaf(TreeNode *root) {
    vector<int> v = {};
    vector<vector<int>> res = {};
    rec(res, v, root);

    return res;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
