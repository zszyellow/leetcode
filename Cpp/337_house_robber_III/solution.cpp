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
  int rob(TreeNode* root) {
    vector<int> res = dfs(root);
    return max(res[0], res[1]);
  }
    
  // first element is the amount without root itself, second element is the amount with root itself.
  vector<int> dfs(TreeNode *root) {
    if (!root) return vector<int>(2, 0);
    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);
    vector<int> res(2, 0);
    res[0] = max(left[0], left[1]) + max(right[0], right[1]);
    res[1] = left[0] + right[0] + root->val;
    return res;
  }
};
