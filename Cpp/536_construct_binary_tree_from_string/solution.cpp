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
  TreeNode* str2tree(string s) {
    int i = 0;
    return  s.size() == 0 ? NULL : build(s, i);
  }
    
  TreeNode* build(string& s, int &i) {
    int start = i;
    if (s[i] == '-') i ++;
    while (std::isdigit(s[i])) i ++;
    int num = std::stoi(s.substr(start, i - start));
    TreeNode* node = new TreeNode(num);
    if (s[i] == '(') {
      node->left = build(s, ++i);
      i ++;    
    }
    if (s[i] == '(') {
      node->right = build(s, ++i);
      i ++;   
    }
    return node;
  }
};
