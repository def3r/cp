#include "dbg.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
  void preorder(TreeNode *root, stringstream &ss) {
    if (root == nullptr)
      return;
    ss << root->val;
    if (root->left) {
      ss << "L";
      preorder(root->left, ss);
    }
    if (root->right) {
      ss << "R";
      preorder(root->right, ss);
    }
    ss << "B";
  }

  int next(string &s) {
    int mIdx = 0;
    while (!(s[mIdx] >= '0' && s[mIdx] <= '9'))
      mIdx++;

    int i = stoi(s.substr(0, mIdx));
    s = s.substr(mIdx);

    return i;
  }

  TreeNode *buildTree(string &data) {
    if (data == "E")
      return nullptr;
    TreeNode *node = new TreeNode(next(data));

    if (data.front() == 'L') {
      data = data.substr(1);
      node->left = buildTree(data);
    }

    if (data.front() == 'R') {
      data = data.substr(1);
      node->right = buildTree(data);
    }

    if (data.front() == 'B') {
      data = data.substr(1);
      return node;
    }

    return node;
  }

public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    // L left, R right, B backtrack, E end
    // 1L2BR3L3BR5E
    stringstream ss;
    preorder(root, ss);

    string s = ss.str();
    while (s.back() != 'B')
      s.pop_back();
    s.push_back('E');

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data == "E")
      return nullptr;
    return buildTree(data);
  }
};

// class Codec {
// private:
//   void order(TreeNode *root, stringstream &in, stringstream &pre) {
//     if (root == nullptr)
//       return;
//     pre << "," << root->val;
//     order(root->left, in, pre);
//     in << "," << root->val;
//     order(root->right, in, pre);
//   }
//
// public:
//   // Encodes a tree to a single string.
//   string serialize(TreeNode *root) {
//     // Inorder:Preorder
//     // 3,2,1:1,2,3
//     stringstream in, pre;
//     order(root, in, pre);
//     return in.str() + ":" + pre.str();
//   }
//
//   // Decodes your encoded data to tree.
//   TreeNode *deserialize(string data) {
//     int sep = data.find(":");
//     string in = data.substr(0, sep);
//     string pre = data.substr(sep + 1);
//
//     vector<int> inO = {}, preO = {};
//     while ((sep = in.find(",")) != string::npos) {
//       inO.push_back(stoi(in.substr(0, sep)));
//       in = in.substr(sep + 1);
//     }
//     inO.push_back(stoi(in));
//
//     while ((sep = pre.find(",")) != string::npos) {
//       preO.push_back(stoi(pre.substr(0, sep)));
//       pre = pre.substr(sep + 1);
//     }
//     preO.push_back(stoi(pre));
//
//     dbg_print_each(inO);
//     dbg_print_each(preO);
//
//     return 0;
//   }
// };

#undef dbg_test_fun
int main() {
  // Codec ser, deser;
  // TreeNode *ans = deser.deserialize(ser.serialize(root));

#define dbg_test_fun // func

  return EXIT_SUCCESS;
}
