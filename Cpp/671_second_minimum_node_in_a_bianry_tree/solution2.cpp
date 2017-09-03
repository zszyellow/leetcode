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
    void process(set<int>& s, TreeNode* root)
    {
        if (root == NULL) return;
        s.insert(root->val);
        process(s, root->left);
        process(s, root->right);
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        process(s, root);
        if (s.size() < 2) return -1;
        auto it = s.begin();
        return *(++it);
    }
};