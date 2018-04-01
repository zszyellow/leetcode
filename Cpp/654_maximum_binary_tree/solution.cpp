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
