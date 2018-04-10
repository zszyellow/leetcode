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
  int countUnivalSubtrees(TreeNode* root) {
    int res = 0;
    dfs(root, res);
    return res;
  }
    
  bool dfs(TreeNode* root, int &res) {
    if (!root) return false;
    bool left = dfs(root->left, res);
    bool right = dfs(root->right, res);
    if (!(root->left) && !(root->right) ||
        left && right && root->val == root->left->val && root->val == root->right->val ||
        !(root->left) && right && root->val == root->right->val ||
        !(root->right) && left && root->val == root->left->val) {
      res ++;
      return true;
    }
    return false;
  }
};
