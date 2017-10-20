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
    // bottom to top
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;     
    }
    
    int height(TreeNode *root) {
        if (!root) return 0;
        int left = height(root->left);
        if (left == -1) return -1;
        int right = height(root->right);
        if (right == -1) return -1;
        if (abs(left-right) > 1)  return -1;
        return std::max(left, right) + 1;
    }