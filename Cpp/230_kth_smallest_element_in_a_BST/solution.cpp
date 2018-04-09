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
  int kthSmallest(TreeNode* root, int k) {
    vector<int> tmp;
    inorderTraverse(root, tmp);
    return tmp[k-1];
  }
    
  void inorderTraverse(TreeNode* root, vector<int> &tmp) {
    if (!root) return;
    inorderTraverse(root->left, tmp);
    tmp.push_back(root->val);
    inorderTraverse(root->right, tmp);
  }
};
