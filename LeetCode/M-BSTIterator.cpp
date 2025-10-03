#include "dbg.h"
#include <stack>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode *root) { leftmostLeaf(root); }

  int next() {
    TreeNode *top = s.top();
    s.pop();
    leftmostLeaf(top->right);
    return top->val;
  }

  bool hasNext() { return !s.empty(); }

private:
  stack<TreeNode *> s = {};

  void leftmostLeaf(TreeNode *root) {
    while (root != nullptr) {
      s.push(root);
      root = root->left;
    }
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
