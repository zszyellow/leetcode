/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
private:
    int prev;
    int res;
public:
    int minDiffInBST(TreeNode* root) {
        prev = INT_MAX;
        res = INT_MAX;
        helper(root);
        return res;
    }
    
    void helper(TreeNode* root) {
        if (!root) return; 
        helper(root->left);
        if (prev != INT_MAX) res = min(res, root->val - prev);
        prev = root->val;
        helper(root->right);
    }
};

