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
   TreeNode* first = NULL;
   TreeNode* second = NULL;
   TreeNode* prev = new TreeNode(INT_MIN);

   void recoverTree(TreeNode* root) {
       inorderTraverse(root);
       int tmp = first->val;
       first->val = second->val;
       second->val = tmp;
   }   
   
   void inorderTraverse(TreeNode* root) 
   {
       if (!root) return;
       inorderTraverse(root->left);
       if (!first && prev->val >= root->val) first = prev;
       if (first && prev->val >= root->val) second = root;
       prev = root;
       inorderTraverse(root->right);
   }
};