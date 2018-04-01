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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return startPath(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    
    int startPath(TreeNode* root, int pre, int sum) {
        if (!root) return 0;
        int cur = pre + root->val;
        return (cur == sum) + startPath(root->left, cur, sum) + startPath(root->right, cur, sum);
    }
    
    
};
