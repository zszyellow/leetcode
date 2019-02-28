/*
 * @lc app=leetcode id=998 lang=cpp
 *
 * [998] Maximum Binary Tree II
 *
 * https://leetcode.com/problems/maximum-binary-tree-ii/description/
 *
 * algorithms
 * Medium (61.98%)
 * Total Accepted:    3.8K
 * Total Submissions: 6K
 * Testcase Example:  '[4,1,3,null,null,2]\n5'
 *
 * We are given the root node of a maximum tree: a tree where every node has a
 * value greater than any other value in its subtree.
 * 
 * Just as in the previous problem, the given tree was constructed from an list
 * A (root = Construct(A)) recursively with the following Construct(A)
 * routine:
 * 
 * 
 * If A is empty, return null.
 * Otherwise, let A[i] be the largest element of A.  Create a root node with
 * value A[i].
 * The left child of root will be Construct([A[0], A[1], ..., A[i-1]])
 * The right child of root will be Construct([A[i+1], A[i+2], ..., A[A.length -
 * 1]])
 * Return root.
 * 
 * 
 * Note that we were not given A directly, only a root node root =
 * Construct(A).
 * 
 * Suppose B is a copy of A with the value val appended to it.  It is
 * guaranteed that B has unique values.
 * 
 * Return Construct(B).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [4,1,3,null,null,2], val = 5
 * Output: [5,4,null,1,3,null,null,2]
 * Explanation: A = [1,4,2,3], B = [1,4,2,3,5]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * Input: root = [5,2,4,null,1], val = 3
 * Output: [5,2,4,null,1,null,3]
 * Explanation: A = [2,1,5,4], B = [2,1,5,4,3]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * 
 * Input: root = [5,2,3,null,1], val = 4
 * Output: [5,2,4,null,1,3]
 * Explanation: A = [2,1,5,3], B = [2,1,5,3,4]
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= B.length <= 100
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> original_list = findOriginalList(root);
        original_list.push_back(val);
        return constructMaximumBinaryTree(original_list);
    }

    vector<int> findOriginalList(TreeNode* root) {
        if (!root) return vector<int>();
        else {
            auto left = findOriginalList(root->left);
            auto right = findOriginalList(root->right);
            left.push_back(root->val);
            left.insert(left.end(), right.begin(), right.end());
            return left;
        }
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
    
    TreeNode* construct(vector<int>& nums, int beg, int end) {
        if (beg > end) return NULL;
        else if (beg == end) return new TreeNode(nums[beg]);
        else {
            int maxIdx = 0, max = INT_MIN;
            for (int i = beg; i <= end; i ++) {
                if (nums[i] > max) {
                    max = nums[i];
                    maxIdx = i;
                }
            }
            TreeNode* res = new TreeNode(max);
            res->left = construct(nums, beg, maxIdx-1);
            res->right = construct(nums, maxIdx+1, end);   
            return res;
        }
    }
};

