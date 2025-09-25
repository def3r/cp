#include "dbg.h"
#include <queue>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrderBetter(TreeNode *root) {
  if (root == nullptr)
    return {};
  vector<vector<int>> res = {};
  queue<TreeNode *> q;
  bool flag = true; // left to right
  q.push(root);

  while (!q.empty()) {
    int size = q.size();
    vector<int> v(size);

    for (int i = 0; i < size; i++) {
      TreeNode *front = q.front();
      q.pop();

      int idx = (flag) ? i : size - 1 - i;
      v[idx] = front->val;

      if (front->left)
        q.push(front->left);
      if (front->right)
        q.push(front->right);
    }

    flag = !flag;
    res.push_back(v);
  }

  return res;
}

vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
  if (root == nullptr)
    return {};
  vector<vector<int>> res = {};
  deque<TreeNode *> dq;
  bool f = true;
  dq.push_back(root);

  while (!dq.empty()) {
    int s = dq.size();
    vector<int> v = {};

    while (s--) {
      TreeNode *node = f ? dq.front() : dq.back();
      if (f) {
        dq.pop_front();
        if (node->left)
          dq.push_back(node->left);
        if (node->right)
          dq.push_back(node->right);
      } else {
        dq.pop_back();
        if (node->right)
          dq.push_front(node->right);
        if (node->left)
          dq.push_front(node->left);
      }
      v.push_back(node->val);
    }
    f = !f;
    res.push_back(v);
  }

  return res;
}

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
