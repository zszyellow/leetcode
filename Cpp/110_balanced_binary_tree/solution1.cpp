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
    // top to bottom
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        return abs(left-right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int depth(TreeNode* root)
    {
        if (!root) return 0;
        return std::max(depth(root->left), depth(root->right))+1;
    }
};