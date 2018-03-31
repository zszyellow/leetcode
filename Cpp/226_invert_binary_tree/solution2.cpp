/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root) return root;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            TreeNode* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return root;
    }
};