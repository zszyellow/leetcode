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
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int t1 = depth(root->left) + depth(root->right);
    int t2 = std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
    return std::max(t1, t2);
  }
    
  int depth(TreeNode* root) {
    if (!root) return 0;
    return 1 + std::max(depth(root->left), depth(root->right));
  }
};
