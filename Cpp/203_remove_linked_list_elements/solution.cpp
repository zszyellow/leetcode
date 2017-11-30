/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        auto cur = head;
        while (head && cur->val == val) 
        {
            head = head->next;
            cur = head;
        }
        if (!head || !(head->next)) return head;
    
        auto pre = head;
        for (cur = head->next; cur; cur = cur->next)
        {
            if (cur->val == val)
                pre->next = cur->next;
            else
                pre = cur;
        }
        return head;
    }
};