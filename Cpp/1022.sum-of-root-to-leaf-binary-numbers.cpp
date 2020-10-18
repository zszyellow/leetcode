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
    void dfs(TreeNode* root, int &sum, int cur) {
        if (root == nullptr) return;
        cur = (cur << 1) | root->val;

        if (!root->left && !root->right) {
            sum += cur;
        } else {
            dfs(root->left, sum, cur);
            dfs(root->right, sum, cur);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int res = 0, cur = 0;
        dfs(root, res, cur);
        return res;
    }
};