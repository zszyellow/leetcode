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
    int sumEvenGrandparent(TreeNode *root) {
        int res = 0;
        dfs(root, nullptr, nullptr, res);
        return res;
    }
    
    void dfs(TreeNode *root, TreeNode *parent, TreeNode *grand_parent, int &res) {
        if (root == nullptr) return;
        if (grand_parent != nullptr && grand_parent->val % 2 ==0) res += root->val;
        dfs(root->left, root, parent, res);
        dfs(root->right, root, parent, res);
    }
};