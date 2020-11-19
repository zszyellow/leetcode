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
    TreeNode* correctBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int level_size = q.size();
            
            // pair<childNode, parentNode>
            vector<pair<TreeNode*, TreeNode*>> tmp;
            unordered_set<int> hs;
            for (int i=0; i < level_size; i ++) {
                auto cur = q.front();
                if (cur->left) {
                    q.push(cur->left);
                    tmp.push_back({cur->left, cur});
                    hs.insert(cur->left->val);
                }
                if (cur->right) {
                    q.push(cur->right);
                    tmp.push_back({cur->right, cur});
                    hs.insert(cur->right->val);
                }
                q.pop();
            }
            
            for (auto &&[childNode, parentNode] : tmp) {
                if (childNode->right && hs.count(childNode->right->val)) {
                    if (parentNode->left == childNode) parentNode->left = nullptr;
                    if (parentNode->right == childNode) parentNode->right = nullptr;
                    return root;
                }
            }           
        }
        return root; 
    }
};