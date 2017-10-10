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
        ListNode* cur = head->next;
        int tmp = head->val;
        
        if (cur->val != tmp)
        {
            head->next = deleteDuplicates(cur);
            return head;
        }
        else
        {
            while (cur && cur->val == tmp) cur = cur->next;
            return deleteDuplicates(cur);
        }
    }
};