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
  int longestConsecutive(TreeNode* root) {
    int res = 0;
    dfs(root, root, res);
    return res;
  }
    
  pair<int, int> dfs(TreeNode *cur, TreeNode *parent, int & res) {
    if (!cur) return make_pair(0, 0);
    auto left = dfs(cur->left, cur, res);
    auto right = dfs(cur->right, cur, res);
    res = max(res, left.first + right.second + 1);
    res = max(res, left.second + right.first + 1);
    int inc = 0, dec = 0;
    if (cur->val == parent->val + 1) {
      inc = max(left.first, right.first) + 1;
    }
    if (cur->val == parent->val - 1) {
      dec = max(left.second, right.second) + 1;
    }
    return make_pair(inc, dec);
  }
};
