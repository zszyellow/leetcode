class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        TreeNode* tmp;
        int max, len;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            len = q.size();
            max = INT_MIN;
            for (int i = 0; i < len; i++)
            {
                tmp = q.front();
                q.pop();
                if (max < tmp->val) max = tmp->val;
                if (tmp->left != NULL) q.push(tmp->left);
                if (tmp->right != NULL) q.push(tmp->right);
            }
            res.push_back(max);
        }

        return res;
    }
};
