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
    void dfs(TreeNode* node, vector<int>& res, int nchild) {
        if (nullptr == node) return;
        if (nchild == 1) res.push_back(node->val);
        nchild = (node->left == nullptr) + (node->right == nullptr);
        dfs(node->left, res, nchild);
        dfs(node->right, res, nchild);
    }
    
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};