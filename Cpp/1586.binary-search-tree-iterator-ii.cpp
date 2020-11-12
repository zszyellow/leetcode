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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        fillStack(root, true);
    }
    
    bool hasNext() {
        return !next_st.empty();
    }
    
    int next() {
        auto [cur, notFromPrev] = next_st.top();
        next_st.pop();
        prev_st.push(cur);
        fillStack(cur->right, notFromPrev);
        return cur->val;
    }
    
    bool hasPrev() {
        return prev_st.size() > 1;
    }
    
    int prev() {
        next_st.push({prev_st.top(), false});
        prev_st.pop();
        return prev_st.top()->val;
    }
private:
    stack<pair<TreeNode*, bool>> next_st;
    stack<TreeNode*> prev_st;
    void fillStack(TreeNode *node, bool notFromPrev) {
        while (node && notFromPrev) {
            next_st.push({node, true});
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */