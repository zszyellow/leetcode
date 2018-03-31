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
  bool findTarget(TreeNode* root, int k) {
    vector<int> nums;
    inorderTraversal(root, nums);
    return findTarget(nums, k);
  }
    
  void inorderTraversal(TreeNode* root, vector<int> &nums) {
    if (!root) return;
    inorderTraversal(root->left, nums);
    nums.push_back(root->val);
    inorderTraversal(root->right, nums);
  }
    
  bool findTarget(vector<int> nums, int k) {
    int a = 0, b = nums.size()-1;
        
    while (a < b) {
      int tmp = nums[a] + nums[b];
      if (tmp == k) return true;
      else if (tmp < k) a ++;
      else if (tmp > k) b --;
    }
    return false;
  }
};
