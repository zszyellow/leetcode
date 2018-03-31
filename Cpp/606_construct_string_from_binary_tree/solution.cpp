/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  string tree2str(TreeNode* t) {
    if (!t) return "";
    string res = std::to_string(t->val);
        
    if (!t->left) {
      if (t->right) res += "()(" + tree2str(t->right) + ")";
    } else {
      res += "(" + tree2str(t->left) + ")";
      if (t->right) res += "(" + tree2str(t->right) + ")";
    }
    return res;
  }
};res += "(" + tree2str(t->right) + ")";
