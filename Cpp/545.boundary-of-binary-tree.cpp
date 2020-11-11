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
    bool isLeaf(TreeNode *root) {
        return root->left == nullptr && root->right == nullptr;
    }
    
    void addLeftBoundary(TreeNode *node, vector<int> &res) {
        while (node) {
            if (!isLeaf(node)) res.push_back(node->val);
            if (node->left) node = node->left;
            else node = node->right;
        }
    }
    
    void addLeaves(TreeNode *root, vector<int> &res) {
        if (isLeaf(root)) res.push_back(root->val);
        else {
            if (root->left) addLeaves(root->left, res);
            if (root->right) addLeaves(root->right, res);
        }
    }
    
    void addRightBoundary(TreeNode *node, vector<int> &res) {
        stack<int> st;
        while (node) {
            if (!isLeaf(node)) st.push(node->val);
            if (node->right) node = node->right;
            else node = node->left;
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;
        if (!isLeaf(root)) res.push_back(root->val);
        
        addLeftBoundary(root->left, res);
        addLeaves(root, res);
        addRightBoundary(root->right, res);
        
        return res;
    }
};