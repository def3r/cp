#include "dbg.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>

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
  int amountOfTime(TreeNode *root, int start) {
    if (root == nullptr)
      return 0;
    unordered_map<TreeNode *, TreeNode *> parent = {};
    TreeNode *target = nullptr;
    int res = 0;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *front = q.front();
        q.pop();

        if (front->val == start)
          target = front;

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

    unordered_set<TreeNode *> visited = {};
    q.push(target);
    visited.insert(target);
    res = -1;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        TreeNode *front = q.front();
        q.pop();

        if (front->left != nullptr &&
            visited.find(front->left) == visited.end()) {
          q.push(front->left);
          visited.insert(target);
        }
        if (front->right != nullptr &&
            visited.find(front->right) == visited.end()) {
          visited.insert(target);
          q.push(front->right);
        }
        if (parent[front] != nullptr &&
            visited.find(parent[front]) == visited.end()) {
          visited.insert(target);
          q.push(parent[front]);
        }
      }
      res++;
    }

    return res;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
