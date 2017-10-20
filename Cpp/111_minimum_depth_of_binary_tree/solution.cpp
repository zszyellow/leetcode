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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        
        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode* p = q.front();
                q.pop();
                if (!p->left && !p->right) 
                {
                    flag = true;
                    break;
                }
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            res ++;
            if (flag) return res;
        }
        return res;
    }
};