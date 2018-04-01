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
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        if (root) dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int &res) {
        int cl = root->left ? dfs(root->left, res) : 0;
        int cr = root->right ? dfs(root->right, res) : 0;
        int pl = root->left && root->left->val == root->val ? cl + 1 : 0;
        int pr = root->right && root->right->val == root->val ? cr + 1 : 0;
        res = std::max(res, pl+pr);
        return std::max(pl, pr);
    }
};
