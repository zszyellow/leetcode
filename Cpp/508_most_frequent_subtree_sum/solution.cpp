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
  vector<int> findFrequentTreeSum(TreeNode* root) {
    vector<int> res;
    if (!root) return res;
        
    unordered_map<int, int> m;
    int maxCnt = 0;
    countSubTree(root, m, maxCnt);
        
    for (auto i : m) {
      if (i.second == maxCnt) 
        res.push_back(i.first);
    }
    return res;
  }
    
  int countSubTree(TreeNode* root, unordered_map<int, int> &m, int &maxCnt) {
    if (!root) return 0;
    int sum = root->val;
    sum += countSubTree(root->left, m, maxCnt);
    sum += countSubTree(root->right, m, maxCnt);
    m[sum] ++;
    maxCnt = std::max(maxCnt, m[sum]);
    return sum;
  }
    
};
