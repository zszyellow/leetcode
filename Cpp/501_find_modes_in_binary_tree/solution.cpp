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
private:
    vector<int> modes;
    void getMaxFreq(TreeNode* root, int& maxFreq, int& preVal, int& dupCount) {
        if (!root) return;
        getMaxFreq(root->left, maxFreq, preVal, dupCount);
        getMaxFreq(root->right, maxFreq=max(maxFreq, dupCount), preVal=root->val, ++(dupCount*=(root->val==preVal)));
    }
    
    void getMode(TreeNode* root, const int maxFreq, int& preVal, int& dupCount) {
        if (!root) return;
        getMode(root->left, maxFreq, preVal, dupCount);
        if (maxFreq == ++(dupCount*=(root->val==preVal))) modes.push_back(root->val);
        getMode(root->right, maxFreq, preVal=root->val, dupCount);
    }
public:
    vector<int> findMode(TreeNode* root) {
        int maxFreq;
        int preVal;
        int dupCount;
        getMaxFreq(root, maxFreq=0, preVal, dupCount=0); 
        getMode(root, maxFreq, preVal, dupCount=0);      
        return modes;
    }
};
