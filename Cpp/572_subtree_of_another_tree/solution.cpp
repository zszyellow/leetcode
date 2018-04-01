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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isTheSame(s, t)) return true;
        else if (!s && t || s && !t) return false;
        else if (isSubtree(s->left, t) || isSubtree(s->right, t)) return true;
        return false;
    }

    bool isTheSame(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        else if (!s && t || s && !t) return false;
        else if (s->val == t->val && 
            isTheSame(s->left, t->left) &&
            isTheSame(s->right, t->right))
            return true;
        return false;
    }
};
