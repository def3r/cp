#include "dbg.h"
#include <stack>
#include <utility>

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
  bool inorder(TreeNode *root) {
    if (root == nullptr)
      return false;

    if (inorder(root->left))
      return true;
    if (!s.empty() && root->val < s.top()->val) {
      if (!node1) {
        while (!s.empty() && s.top()->val > root->val) {
          node1 = s.top();
          s.pop();
        }
        node2 = root;
      } else {
        node2 = root;
        return true;
      }
    }
    s.push(root);

    return inorder(root->right);
  }

  void recoverTree(TreeNode *root) {
    node1 = node2 = 0;
    inorder(root);
    swap(node1->val, node2->val);
  }

private:
  stack<TreeNode *> s = {};
  TreeNode *node1 = 0, *node2 = 0;
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
