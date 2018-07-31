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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1 = getLeaves(root1);
        vector<int> seq2 = getLeaves(root2);
        return seq1 == seq2;
    }
    
    vector<int> getLeaves(TreeNode* root) {
        vector<int> leaves;
        dfs(root, leaves);
        return leaves;
    }
    
    void dfs(TreeNode* cur, vector<int>& leaves) {
        if (!cur) return;
        else if (cur->left == NULL && cur->right == NULL) leaves.push_back(cur->val);
        else {
            dfs(cur->left, leaves);
            dfs(cur->right, leaves);
        }
    }
};