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
  int widthOfBinaryTree(TreeNode* root) {
    vector<int> lefts; 
    return dfs(root, 1, 0, lefts);
  }
private:
  int dfs(TreeNode* n, int id, int depth, vector<int>& lefts) { 
    if (!n) return 0;
    if (depth >= lefts.size()) lefts.push_back(id);
    return max({id + 1 - lefts[depth], dfs(n->left, id * 2, depth + 1, lefts), dfs(n->right, id * 2 + 1, depth + 1, lefts)});
  }
};
