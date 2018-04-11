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
  int longestConsecutive(TreeNode* root) {
    return search(root, NULL, 0);
  }
    
  int search(TreeNode *root, TreeNode *parent, int len) {
    if (!root) return len;
    len = (parent && root->val == parent->val + 1) ? len+1 : 1;
    return max(len, max(search(root->left, root, len), search(root->right, root, len)));
  }
};
