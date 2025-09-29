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
  vector<int> getInorder(TreeNode *root) {
    vector<int> res = {};

    while (root != nullptr) {
      if (root->left) {
        TreeNode *rightmost = root->left;
        while (rightmost->right != nullptr && rightmost->right != root) {
          rightmost = rightmost->right;
        }

        if (rightmost->right == nullptr) {
          rightmost->right = root;
          root = root->left;
          continue;
        }
        rightmost->right = nullptr;
      }

      res.push_back(root->data);
      root = root->right;
    }

    return res;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
