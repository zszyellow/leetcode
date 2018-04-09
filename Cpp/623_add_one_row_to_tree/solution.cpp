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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode *newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        else {
            traverse(root, v, d, 2);
            return root;   
        }
    }
    
private:
    void traverse(TreeNode* root, int v, int d, int curDep) {
        if (!root) return;
        if (curDep == d) {
            TreeNode *curleft = root->left;
            root->left = new TreeNode(v);
            root->left->left = curleft;
            TreeNode *curRight = root->right;
            root->right = new TreeNode(v);
            root->right->right = curRight;
            return;
        }
        traverse(root->left, v, d, curDep + 1);
        traverse(root->right, v, d, curDep + 1);
    }
};
