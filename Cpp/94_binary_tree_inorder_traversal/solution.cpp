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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while (!st.empty() || root)
        {
            if (root) 
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};