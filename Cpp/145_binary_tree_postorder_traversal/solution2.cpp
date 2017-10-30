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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        TreeNode* lastVisited(NULL);
        
        while (!st.empty() || root)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else 
            {
                auto peek = st.top();
                if (peek->right && lastVisited != peek->right) root = peek->right;
                else 
                {
                    res.push_back(peek->val);
                    lastVisited = peek;
                    st.pop();
                }
            }
        }
        
        return res;
    }
};