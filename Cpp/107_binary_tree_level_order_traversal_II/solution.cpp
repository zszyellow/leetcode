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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> tmp;
            int size = q.size();
            for (int i = 0; i < size; i ++)
            {
                TreeNode* p = q.front();
                q.pop();
                tmp.push_back(p->val);
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            res.push_back(tmp);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};