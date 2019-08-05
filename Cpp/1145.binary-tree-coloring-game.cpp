/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
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
    int left;
    int right;
    int val;
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x;
        dfs(root);
        return max(max(left, right), n - left - right - 1) > n / 2;
    }
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (val == root->val) {
            left = l;
            right = r;
        }
        return l + r + 1;
    }
};