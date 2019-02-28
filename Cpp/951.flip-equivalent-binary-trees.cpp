/*
 * @lc app=leetcode id=951 lang=cpp
 *
 * [951] Flip Equivalent Binary Trees
 *
 * https://leetcode.com/problems/flip-equivalent-binary-trees/description/
 *
 * algorithms
 * Medium (64.89%)
 * Total Accepted:    10.3K
 * Total Submissions: 15.9K
 * Testcase Example:  '[1,2,3,4,5,6,null,null,null,7,8]\n[1,3,2,null,6,4,5,null,null,null,null,8,7]'
 *
 * For a binary tree T, we can define a flip operation as follows: choose any
 * node, and swap the left and right child subtrees.
 * 
 * A binary tree X is flip equivalent to a binary tree Y if and only if we can
 * make X equal to Y after some number of flip operations.
 * 
 * Write a function that determines whether two binary trees are flip
 * equivalent.  The trees are given by root nodes root1 and root2.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 =
 * [1,3,2,null,6,4,5,null,null,null,null,8,7]
 * Output: true
 * Explanation: We flipped at nodes with values 1, 3, and 5.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * Each tree will have at most 100 nodes.
 * Each value in each tree will be a unique integer in the range [0, 99].
 * 
 * 
 * 
 * 
 * 
 * 
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
    bool flipEquiv(TreeNode* a, TreeNode* b) {
        if (!a && !b) return true;
        else if (!a && b || !b && a) return false;
        else if (!a->left && !a->right && !b->left && !b->right) return true;
        else if (a->left && !a->right) {
            if (b->left && b->left->val == a->left->val && !b->right) return flipEquiv(a->left, b->left);
            else if (!b->left && b->right && a->left->val == b->right->val) return flipEquiv(a->left, b->right);
            else return false;
        }
        else if (!a->left && a->right) {
            if (b->left && !b->right && b->left->val == a->right->val) return flipEquiv(a->right, b->left);
            else if (!b->left && b->right && a->right->val == b->right->val) return flipEquiv(a->right, b->right);
            else return false;
        }
        else if (b->left && b->right) {
            if (a->left->val == b->left->val && a->right->val == b->right->val) return flipEquiv(a->left, b->left) && flipEquiv(a->right, b->right);
            else if (a->left->val == b->right->val && a->right->val == b->left->val)  return flipEquiv(a->left, b->right) && flipEquiv(a->right, b->left);
            else return false;
        }
        else return false;
    }
};

