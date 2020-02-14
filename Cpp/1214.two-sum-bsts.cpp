/*
 * @lc app=leetcode id=1214 lang=cpp
 *
 * [1214] Two Sum BSTs
 */

// @lc code=start
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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> hash_set;
        buildHashSet(root1, hash_set);
        return findTarget(root2, target, hash_set);
    }
    
    void buildHashSet(TreeNode* root1, unordered_set<int>& hash_set) {
        if (!root1) return;
        hash_set.insert(root1->val);
        buildHashSet(root1->left, hash_set);
        buildHashSet(root1->right, hash_set);
    }
    
    bool findTarget(TreeNode* root2, int target, unordered_set<int>& hash_set) {
        if (!root2) return false;
        int complement = target - root2->val;
        if (hash_set.find(complement) != hash_set.end()) return true;
        else return findTarget(root2->left, target, hash_set) || findTarget(root2->right, target, hash_set);
    }
};
// @lc code=end

