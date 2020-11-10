/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        dfs(root1, arr1);
        dfs(root2, arr2);
        
        int p1 = 0, p2 = 0;
        vector<int> res;
        while (p1 < arr1.size() && p2 < arr2.size()) {
            if (arr1[p1] <= arr2[p2]) 
                res.push_back(arr1[p1 ++]);
            else 
                res.push_back(arr2[p2 ++]);
        }
        
        while (p1 < arr1.size()) res.push_back(arr1[p1 ++]);
        while (p2 < arr2.size()) res.push_back(arr2[p2 ++]);
        return res;
    }
    
    void dfs(TreeNode *root, vector<int> &arr) {
        if (root == nullptr) return;
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
    }
};