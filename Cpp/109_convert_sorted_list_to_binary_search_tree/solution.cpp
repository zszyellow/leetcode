/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *list;
    
    int length(ListNode *node)
    {
        for (int i = 0; ; node = node->next, i ++) 
            if (!node) return i;
    }
    
    TreeNode *generate(int n)
    {
        if (!n) return NULL;
        TreeNode *node = new TreeNode(0);
        node->left = generate(n/2);
        node->val = list->val;
        list = list->next;
        node->right = generate(n-n/2-1);
        return node;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        this->list = head;
        return generate(length(head));
    }
};