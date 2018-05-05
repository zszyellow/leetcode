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
    int findClosestLeaf(TreeNode* root, int k) {
        if (!root) return 0;
        if (!root->left && !root->right) return k;
        G.clear(); G.resize(1001); go(root);
        return bfs(root->val,k);
    }

private:
    vector<vector<int>> G;

    void go(TreeNode* root) {
        if (root->left){ link(root,root->left); go(root->left); }
        if (root->right){ link(root,root->right); go(root->right); }
    }

    void link(TreeNode* parent, TreeNode* child) {
        G[parent->val].push_back(child->val);
        G[child->val].push_back(parent->val);
    }

    int bfs(int root, int target){
        unordered_set<int> v({target});
        queue<int> q({target});
        while (!q.empty()){
            auto curr=q.front(); q.pop();
            if (curr!=root && G[curr].size()==1) return curr; // leaf node has 1 neighbor (except root)
            for (auto nei: G[curr])
                if (v.find(nei)==v.end()){ q.push(nei); v.insert(nei); }
        }
        return -1;
    }
};
