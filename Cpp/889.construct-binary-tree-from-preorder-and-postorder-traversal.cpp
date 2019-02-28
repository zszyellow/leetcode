/*
 * @lc app=leetcode id=889 lang=cpp
 *
 * [889] Construct Binary Tree from Preorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (57.68%)
 * Total Accepted:    11.5K
 * Total Submissions: 20K
 * Testcase Example:  '[1,2,4,5,3,6,7]\n[4,5,2,6,7,3,1]'
 *
 * Return any binary tree that matches the given preorder and postorder
 * traversals.
 * 
 * Values in the traversals pre and post are distinct positive integers.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
 * Output: [1,2,3,4,5,6,7]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= pre.length == post.length <= 30
 * pre[] and post[] are both permutations of 1, 2, ..., pre.length.
 * It is guaranteed an answer exists. If there exists multiple answers, you can
 * return any of them.
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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.empty()) return NULL;
        else if (pre.size() == 1) return new TreeNode(pre[0]);
        else {
            auto it = std::find(post.begin(), post.end(), pre[1]);
            int left_length = std::distance(post.begin(), it) + 1;
            auto root = new TreeNode(pre[0]);
            int whole_legth = pre.size();
            vector<int> pre_left(pre.begin()+1, pre.begin()+left_length+1);
            vector<int> pre_right(pre.begin()+left_length+1, pre.end());
            vector<int> post_left(post.begin(), post.begin()+left_length);
            vector<int> post_right(post.begin()+left_length, post.begin()+(whole_legth-1));
            
            root->left = constructFromPrePost(pre_left, post_left);
            root->right = constructFromPrePost(pre_right, post_right);
            return root;
        }

    }
};

