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
    void bstToArr(TreeNode *root, vector<int> &arr) {
        if (root == nullptr) return;
        bstToArr(root->left, arr);
        arr.push_back(root->val);
        bstToArr(root->right, arr);
    } 
    
    TreeNode* arrToBST(vector<int> &arr, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = arrToBST(arr, start, mid-1);
        root->right = arrToBST(arr, mid+1, end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        bstToArr(root, arr);
        return arrToBST(arr, 0, arr.size()-1);
    }
};