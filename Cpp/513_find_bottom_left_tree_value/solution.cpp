class Solution
{
public:
    int findBottomLeftValue(TreeNode* root)
    {
        if (root == NULL) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if (i == 0) res = t->val;
                if (t->left != NULL) q.push(t->left);
                if (t->right != NULL) q.push(t->right);
            }
        }
        return res;
    }
};
