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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (p && !q || !p && q || p->val != q->val) return false;
        if (p->left && !q->left || !p->left && q->left || !isSameTree(p->left, q->left)) return false;
        if (p->right && !q->right || !p->right && q->right || !isSameTree(p->right, q->right)) return false;
        return true;
    }
};