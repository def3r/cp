#include "dbg.h"
#include <climits>

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  struct data {
    int size = 0;
    int smallest = INT_MAX, largest = INT_MIN;
  };

  data postorder(TreeNode *root) {
    if (root == nullptr)
      return {};

    auto left = postorder(root->left);
    auto right = postorder(root->right);
    if (left.largest < root->data && right.smallest > root->data)
      return {left.size + right.size + 1, min(root->data, left.smallest),
              max(root->data, right.largest)};

    return {max(left.size, right.size), INT_MIN, INT_MAX};
  }

  int largestBST(TreeNode *root) { return postorder(root).size; }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
