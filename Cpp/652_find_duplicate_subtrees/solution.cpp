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
  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, vector<TreeNode*>> m;
    vector<TreeNode*> res;
    serialize(root, m);
    for (auto it = m.begin(); it != m.end(); it ++) {
      if (it->second.size() > 1) res.push_back(it->second[0]);
    }
    return res;
  }
  
  string serialize(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map) {
    if (!node) return "";
    string res = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
    map[res].push_back(node);
    return res;
  }
};
