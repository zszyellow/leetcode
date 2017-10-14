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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>();
        return generateTree(1, n); 
    }
    
    vector<TreeNode*> generateTree(int start, int end)
    {
        vector<TreeNode*> trees;
        if (start > end)
        {
            trees.push_back(NULL);
            return trees;
        }
        else if (start == end)
        {
            TreeNode* tmp = new TreeNode(start);
            trees.push_back(tmp);
            return trees;
        }
        
        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for (int i = start; i <= end; i ++)
        {
            left = generateTree(start, i-1);
            right = generateTree(i+1, end);
            for (TreeNode* lnode : left)
            {
                for (TreeNode* rnode : right)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = lnode;
                    root->right = rnode;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};