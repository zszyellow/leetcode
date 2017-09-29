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
    static bool compareNode(const TreeNode* a, const TreeNode* b)
    {
        return a->val < b->val;    
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        if (root == NULL || root->left == NULL || root->right == NULL) return -1;
        int min = root->val;
        vector<int> res;
        queue<TreeNode*> q;
        queue<TreeNode*> next;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left != NULL) next.push(cur->left);
            if (cur->right != NULL) next.push(cur->right);
            if (q.empty())
            {
                vector<TreeNode*> tmp;
                queue<TreeNode*> tmp2(next);
                while(!tmp2.empty())
                {
                    tmp.push_back(tmp2.front());
                    tmp2.pop();
                }  
                sort(tmp.begin(), tmp.end(), compareNode);
                
                for (auto it = tmp.begin(); it != tmp.end(); it ++)
                {
                    if ((*it)->val > min) 
                        res.push_back((*it)->val);
                }
                queue<TreeNode*> tmp3(q);
                q = next;
                next = tmp3;
            }
        }
        if (res.empty()) return -1;
        else 
        {
            sort(res.begin(), res.end());
            return res.front();
        }
    }
};