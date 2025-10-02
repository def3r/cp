#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  int successor(TreeNode *root, int key, int s) {
    if (root == nullptr)
      return s;
    if (root->data <= key)
      return successor(root->right, key, s);
    s = root->data;
    return successor(root->left, key, s);
  }

  int predecessor(TreeNode *root, int key, int p) {
    if (root == nullptr)
      return p;

    if (root->data >= key)
      return predecessor(root->left, key, p);
    p = root->data;
    return predecessor(root->right, key, p);
  }

  vector<int> succPredBST(TreeNode *root, int key) {
    return {predecessor(root, key, -1), successor(root, key, -1)};
  }
};
