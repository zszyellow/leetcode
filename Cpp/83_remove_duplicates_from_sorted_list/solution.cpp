/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;
        int tmp = head->val;
        ListNode* cur = head->next;
        
        while (cur && cur->val == tmp) cur = cur->next;
        head->next = deleteDuplicates(cur);
        return head;
    }
};