/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode *root, int cur_state) {
        if (root == nullptr) return 0;
        cur_state ^= (1 << root->val);
        if (root->left == nullptr && root->right == nullptr) 
            return (cur_state & (cur_state - 1)) == 0 ? 1 : 0;
        return dfs(root->left, cur_state) + dfs(root->right, cur_state);
    }
};