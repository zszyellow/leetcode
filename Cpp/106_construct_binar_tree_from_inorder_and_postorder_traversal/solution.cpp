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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) return NULL;
        TreeNode *root = new TreeNode(postorder.back());
        TreeNode *p;
        stack<TreeNode*> st;
        
        st.push(root); 
        postorder.pop_back(); 
        while (true)
        {
            if (inorder.back() == st.top()->val) 
            {
                p = st.top();
                st.pop(); 
                inorder.pop_back(); 
                if (!inorder.size()) break;
                if (st.size() && inorder.back() == st.top()->val) continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                st.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                st.top()->right = p; 
                st.push(p); 
            }
        }
        return root;
    }
};