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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> st;
        TreeNode* pre = NULL;
        while (root || !st.empty()) 
        {
            while (root) 
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }    
        return true;
    }
};