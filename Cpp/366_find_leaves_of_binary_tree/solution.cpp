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
private:
    int dfs(TreeNode* root, vector<vector<int>> &res) {
        if (!root) return 0;
        int height = 1  + std::max(dfs(root->left, res), dfs(root->right, res));
        if (height > res.size()) res.push_back(vector<int>());
        res[height-1].push_back(root->val);
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res);
        return res;
    }
};
