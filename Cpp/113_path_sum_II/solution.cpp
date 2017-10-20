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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        findPath(res, path, root, sum);
        return res;
    }
    
    void findPath(vector<vector<int>>& res, vector<int>& path, TreeNode* root, int sum)
    {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum) res.push_back(path);
        findPath(res, path, root->left, sum-root->val);
        findPath(res, path, root->right, sum-root->val);
        path.pop_back();
    }
};