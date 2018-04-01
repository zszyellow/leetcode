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
  int findTilt(TreeNode* root) {
    if (!root) return 0;
    else return findTilt(root->left) + findTilt(root->right) + abs(findSum(root->left) - findSum(root->right));
  }
  int findSum(TreeNode* root) {
    if (!root) return 0;
    // cout <<  root->val + findSum(root->left) + findSum(root->right) << endl;
    return root->val + findSum(root->left) + findSum(root->right);
  }
};
