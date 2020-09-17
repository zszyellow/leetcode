/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */

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
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        int max_depth = getDeepestDepth(root, 0);
        helper(root, max_depth, 1, res);
        return res;
    }
    
    int getDeepestDepth(TreeNode* root, int cur_depth) {
        if (root == nullptr) return cur_depth;
        return max(getDeepestDepth(root->left, cur_depth+1), getDeepestDepth(root->right, cur_depth+1));
    }
    
    void helper(TreeNode* root, int max_depth, int cur_depth, int& res) {
        if (root == nullptr) return;
        if (cur_depth == max_depth) res += root->val;
        else {
            helper(root->left, max_depth, cur_depth+1, res);
            helper(root->right, max_depth, cur_depth+1, res);
        }
    }
};
