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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> res;
    vector<int> layer;
    if (!root) return res;
        
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int size = q.size();
      layer.clear();
      while (size > 0) {
        auto tmp = q.front();
        q.pop();
        layer.push_back(tmp->val);
        if (tmp->left) q.push(tmp->left);
        if (tmp->right) q.push(tmp->right);
        size --;
      }
      double ave = std::accumulate(layer.begin(), layer.end(), 0.0) / layer.size();
      res.push_back(ave);
    }
    return res;
  }
};
