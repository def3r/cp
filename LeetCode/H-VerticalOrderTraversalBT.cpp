#include "dbg.h"
#include <algorithm>
#include <functional>
#include <map>
#include <utility>
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

class Solution {
public:
  void vot(TreeNode *root, int row, int col,
           map<int, map<int, vector<int>>, greater<int>> &m) {
    if (root == nullptr)
      return;
    m[col][row].push_back(root->val);
    vot(root->left, row + 1, col + 1, m);
    vot(root->right, row + 1, col - 1, m);
  }

  vector<vector<int>> verticalTraversal(TreeNode *root) {
    vector<vector<int>> res = {};
    map<int, map<int, vector<int>>, greater<int>> m = {};

    vot(root, 0, 0, m);

    for (auto it = m.begin(); it != m.end(); ++it) {
      vector<int> col;
      for (auto i = it->second.begin(); i != it->second.end(); ++i) {
        sort(i->second.begin(), i->second.end());
        for (int item : i->second)
          col.push_back(item);
      }
      res.push_back(col);
    }

    return res;
  }
};

#undef dbg_test_fun
int main() {

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
