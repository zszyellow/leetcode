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
  int closestValue(TreeNode* root, double target) {
    int a = root->val;
    auto cur = a > target ? root->left : root->right;
    if (!cur) return a;
    int b = closestValue(cur, target);
    return std::abs(a-target) < std::abs(b-target) ? a : b;
  }
};
