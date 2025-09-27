#include "dbg.h"
#include <queue>
#include <unordered_map>
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
  vector<int> res = {};
  if (root == nullptr)
    return res;
  unordered_map<TreeNode *, TreeNode *> parent = {};

  queue<TreeNode *> q = {};
  q.push(root);
  while (!q.empty()) {
    int size = q.size();
    while (size--) {
      TreeNode *front = q.front();
      q.pop();

      if (front->left) {
        parent[front->left] = front;
        q.push(front->left);
      }

      if (front->right) {
        parent[front->right] = front;
        q.push(front->right);
      }
    }
  }

  q.push(target);
  unordered_map<TreeNode *, bool> visited = {};
  while (k--) {
    int size = q.size();
    while (size--) {
      TreeNode *front = q.front();
      visited[front] = true;
      q.pop();

      if (front->left != nullptr && !visited[front->left])
        q.push(front->left);
      if (front->right != nullptr && !visited[front->right])
        q.push(front->right);
      if (parent[front] != nullptr && !visited[parent[front]])
        q.push(parent[front]);
    }
  }

  while (!q.empty()) {
    res.push_back(q.front()->val);
    q.pop();
  }

  return res;
}

class Solution {
public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    vector<int> res = {};
    findTarget(root, target, k, res);
    return res;
  }

private:
  int findTarget(TreeNode *root, TreeNode *target, int k, vector<int> &res) {
    if (root == nullptr)
      return -1;
    if (root == target) {
      findChildren(root, k, res);
      return 1;
    }

    int dist = findTarget(root->left, target, k, res);
    if (dist != -1) {
      if (k == dist)
        res.push_back(root->val);
      else if (k > dist)
        findChildren(root->right, k - dist - 1, res);
      return dist + 1;
    }

    dist = findTarget(root->right, target, k, res);
    if (dist != -1) {
      if (k == dist)
        res.push_back(root->val);
      else if (k > dist)
        findChildren(root->left, k - dist - 1, res);
      return dist + 1;
    }

    return -1;
  }

  void findChildren(TreeNode *root, int k, vector<int> &res) {
    if (root == 0 || k < 0)
      return;
    if (k == 0) {
      res.push_back(root->val);
      return;
    }
    findChildren(root->left, k - 1, res);
    findChildren(root->right, k - 1, res);
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
