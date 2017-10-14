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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = head;
        ListNode* post = head;
        ListNode* tmp = head;
        bool isNoPre = (m == 1);
        int i = 1;
        
        if (!isNoPre)
        {
            for (; i < m-1; i ++) tmp = tmp->next;
            pre = tmp;
        }
        for (; i < n; i ++) tmp = tmp->next;
        post = tmp->next;
        tmp->next = NULL;
        if (isNoPre) 
        {
            ListNode* cur = head;
            head = reverseList(head);
            cur->next = post;
        }
        else
        {
            ListNode* cur = pre->next;
            pre->next = reverseList(cur);
            cur->next = post;
        }
        return head;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        if (!head || !(head->next)) return head;
        ListNode* tmp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return tmp;
    }
};