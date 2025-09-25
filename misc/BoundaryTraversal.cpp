#include "dbg.h"
#include <vector>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void leaves(vector<int> &res, TreeNode *root) {
  if (root == nullptr)
    return;
  if (root->left == nullptr && root->right == nullptr) {
    res.push_back(root->data);
    return;
  }
  leaves(res, root->left);
  leaves(res, root->right);
}

void rightBoundary(vector<int> &res, TreeNode *root) {
  if (root == nullptr)
    return;
  if (root->left == nullptr && root->right == nullptr) // leaf
    return;

  rightBoundary(res, root->right ? root->right : root->left);
  res.push_back(root->data);
}

void leftBoundary(vector<int> &res, TreeNode *root) {
  if (root == nullptr)
    return;
  if (root->left == nullptr && root->right == nullptr) // leaf
    return;

  res.push_back(root->data);
  leftBoundary(res, root->left ? root->left : root->right);
}

vector<int> boundary(TreeNode *root) {
  if (root == nullptr)
    return {};
  vector<int> res = {};

  res.push_back(root->data);
  if (root->left == nullptr && root->right == nullptr)
    return res;
  leftBoundary(res, root->left);
  leaves(res, root);
  rightBoundary(res, root->right);

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
