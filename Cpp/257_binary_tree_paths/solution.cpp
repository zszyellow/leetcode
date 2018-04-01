
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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (!root) return res;
    string tmp = std::to_string(root->val);
    if (!root->left && !root->right) {
      res.push_back(tmp);
    } else {
      traversal(root->left, tmp, res);
      traversal(root->right, tmp, res);   
    }
    return res;
  }
    
  void traversal(TreeNode* root, string tmp, vector<string> &res) {
    if (!root) return;
    tmp = tmp + "->" + std::to_string(root->val);
    if (!root->left && !root->right) {
      res.push_back(tmp);
      return;
    } else {
      traversal(root->left, tmp, res);
      traversal(root->right, tmp, res);
    }
  }
};
