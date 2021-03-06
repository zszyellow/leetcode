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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if (!root) return res;
        helper(res, root);
        return res;
    }
    
    void helper(vector<int>& res, TreeNode* root)
    {
        if (!root) return;
        helper(res, root->left);
        helper(res, root->right);
        res.push_back(root->val);
    }
};