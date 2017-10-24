/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<TreeLinkNode*> level;
            int size = q.size();
            for (int i = 0; i < size; i ++)
            {
                TreeLinkNode* tmp = q.front();
                level.push_back(tmp);
                q.pop();
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            for (int i = 0; i < size; i ++)
            {
                if (i == size-1) (level[i])->next = NULL;
                else (level[i])->next = level[i+1];
            }
        }
    }
};