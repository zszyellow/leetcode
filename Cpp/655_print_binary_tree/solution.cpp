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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        int depth = findDepth(root); 
        int width = calWidth(depth);
        for (int i = 0; i < depth; i ++) {
            res.push_back(vector<string>(width, ""));
        }
        fillElement(root, res, 0, width/2, (width+1)/4);
        return res;
    }
    
    int findDepth(TreeNode* root) {
        if (!root) return 0;
        int ld = findDepth(root->left);
        int rd = findDepth(root->right);
        return 1 + std::max(ld, rd);
    }
    
    int calWidth(int depth) {
        if (depth == 1) return 1;
        return 2 * calWidth(depth-1) + 1;
    }
    
    void fillElement(TreeNode* root, vector<vector<string>> &res, int x, int y, int shift) {
        if (!root) return;
        res[x][y] = std::to_string(root->val);
        fillElement(root->left, res, x+1, y-shift, shift/2);
        fillElement(root->right, res, x+1, y+shift, shift/2);
    }
};
