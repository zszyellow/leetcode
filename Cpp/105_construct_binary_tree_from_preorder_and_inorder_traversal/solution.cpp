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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, preorder.size(), 0, inorder.size(), preorder, inorder);
    }
    
    TreeNode* dfs(int preIdx, int preEnd, int inIdx, int inEnd, vector<int>& preorder, vector<int>& inorder)
    {
        if (preIdx >= preEnd || inIdx >= inEnd) return NULL;
        auto rootIt = std::find(inorder.begin()+inIdx, inorder.begin()+inEnd, preorder[preIdx]);
        int distance = rootIt - inorder.begin() - inIdx;
        TreeNode* root = new TreeNode(preorder[preIdx]);
        root->left = dfs(preIdx+1, preIdx+distance+1, inIdx, inIdx+distance, preorder, inorder);
        root->right = dfs(preIdx+distance+1, preEnd, inIdx+distance+1, inEnd, preorder, inorder);
        return root;
    }
};