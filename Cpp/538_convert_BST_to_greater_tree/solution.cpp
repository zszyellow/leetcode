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
private:
  int sum;
  void convertBST2(TreeNode* root) {
    if (!root) return;
    convertBST2(root->left);
    int tmp = root->val;
    root->val = sum;
    sum -= tmp;
    convertBST2(root->right);
  }
    
  void getSum(TreeNode* root) {
    if (!root) return;
    getSum(root->left);
    sum += root->val;
    getSum(root->right);
  }
public:
  TreeNode* convertBST(TreeNode* root) {
    getSum(root);
    convertBST2(root);
    return root;
  }
};
