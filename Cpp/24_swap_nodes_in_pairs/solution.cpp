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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) return head;
        auto cur = head;
        while(cur != NULL)
        {
            if (cur->next != NULL)
            {
                int tmp = cur->val;
                cur->val = cur->next->val;
                cur->next->val = tmp;
                cur = cur->next->next;
            }
            else break;
        }
        return head;
    }
};