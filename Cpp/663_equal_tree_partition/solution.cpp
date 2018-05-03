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
  bool checkEqualTree(TreeNode* root) {
    if (!root || !root->left && !root->right) return false;
    vector<float> sums;
    float sumOfAll = sum(root, sums);
    if (int(sumOfAll) % 2 != 0) return false;
    sums.pop_back();
    for (auto it = sums.begin(); it != sums.end(); it ++) {
      if (*it == sumOfAll / 2.0) return true;
    }
    return false;
  }
    
  float sum(TreeNode* node, vector<float>& vec) {
    if (!node) return 0.0;
    float res = 0.0 + node->val + sum(node->left, vec) + sum(node->right, vec);
    vec.push_back(res);
    return res;
  }
};
