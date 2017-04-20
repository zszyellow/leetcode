class Solution {
public:
    void flatten(TreeNode* root)
    {
        if (root == NULL) return;
        TreeNode* pre = NULL;
        TreeNode* cur = NULL;
        stack<TreeNode *> s;
        s.push(root);

        while(!s.empty())
        {
            cur = s.top();
            s.pop();
            if(cur->right != NULL) s.push(cur->right);
            if(cur->left != NULL) s.push(cur->left);
            cur->left = NULL;
            if (pre != NULL) pre->right = cur;
            pre = cur;
        }
    }
};
