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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(res, root);
        return res;
    }
    
    int helper(int& max_val, TreeNode* root)
    {
        if (!root) return 0;
        int left = std::max(0, helper(max_val, root->left));
        int right = std::max(0, helper(max_val, root->right));
        max_val = std::max(max_val, left+right+root->val);
        return std::max(left, right) + root->val;
    }
};