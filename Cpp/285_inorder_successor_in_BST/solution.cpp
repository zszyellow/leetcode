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
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* node = root;
    TreeNode* res = NULL;
    if (node == NULL ||p == NULL||root->left == NULL && root->right == NULL) return NULL;

    if (p->right) {
      res = p->right;
      while(res->left != NULL) res = res->left;
      return res;
    }
    else {
      while (node != NULL) {
        if(node == p) break;
        if (node->val > p->val) {
          if(res== NULL || res != NULL && res->val > node->val) res = node;
        }
        if (p->val < node->val) node = node->left;
        else node = node->right;
      }
    }

    return res;
  }
};
