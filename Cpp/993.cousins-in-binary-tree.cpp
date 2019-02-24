/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
 *
 * https://leetcode.com/problems/cousins-in-binary-tree/description/
 *
 * algorithms
 * Easy (53.96%)
 * Total Accepted:    6.2K
 * Total Submissions: 11.5K
 * Testcase Example:  '[1,2,3,4]\n4\n3'
 *
 * In a binary tree, the root node is at depth 0, and children of each depth k
 * node are at depth k+1.
 * 
 * Two nodes of a binary tree are cousins if they have the same depth, but have
 * different parents.
 * 
 * We are given the root of a binary tree with unique values, and the values x
 * and y of two different nodes in the tree.
 * 
 * Return true if and only if the nodes corresponding to the values x and y are
 * cousins.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: root = [1,2,3,4], x = 4, y = 3
 * Output: false
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
 * Output: true
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,null,4], x = 2, y = 3
 * Output: false
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree will be between 2 and 100.
 * Each node has a unique integer value from 1 to 100.
 * 
 * 
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        bool one_found = false;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int cur_level_size = q.size();
            while (cur_level_size -- != 0) {
                TreeNode* tmp = q.front();
                q.pop();

                if (tmp->left && tmp->right && (tmp->left->val == x || tmp->right->val == x) && (tmp->left->val == y || tmp->right->val == y))
                    return false;
                if (one_found && ((tmp->left && (tmp->left->val == x || tmp->left->val == y) || (tmp->right && (tmp->right->val == x || tmp->right->val == y)))))
                    return true;
                if (tmp->left) {
                    if (tmp->left->val == x || tmp->left->val == y) {
                        one_found = true;
                        continue;
                    }
                    q.push(tmp->left);
                }
                if (tmp->right) {
                    if (tmp->right->val == x || tmp->right->val == y) {
                        one_found = true;
                        continue;
                    }
                    q.push(tmp->right);
                }
            }

            if (one_found) return false;
        }
        return false;
    } 
};
