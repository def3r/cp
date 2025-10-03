#include "dbg.h"
#include <stack>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTIterator {
public:
  BSTIterator(TreeNode *root) {
    leftmostLeaf(root);
    rightmostLeaf(root);
  }

  int next() {
    TreeNode *top = in.top();
    in.pop();
    leftmostLeaf(top->right);
    return top->data;
  }

  int before() {
    TreeNode *top = revIn.top();
    revIn.pop();
    rightmostLeaf(top->left);
    return top->data;
  }

  bool hasNext() { return !in.empty(); }
  bool hasBefore() { return !in.empty(); }
  bool nextIsBefore() { return in.top() == revIn.top(); }

private:
  stack<TreeNode *> in = {}, revIn = {};

  void leftmostLeaf(TreeNode *root) {
    while (root != nullptr) {
      in.push(root);
      root = root->left;
    }
  }

  void rightmostLeaf(TreeNode *root) {
    while (root != nullptr) {
      revIn.push(root);
      root = root->right;
    }
  }
};

class Solution {
public:
  bool twoSumBST(TreeNode *root, int k) {
    if (root == nullptr)
      return false;

    BSTIterator it(root);
    int i = it.next(), j = it.before();
    while (i < j) {
      if (i + j == k)
        return true;
      else if (i + j > k)
        j = it.before();
      else
        i = it.next();
    }

    return i + j == k;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
