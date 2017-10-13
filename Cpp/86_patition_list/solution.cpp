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
    ListNode* partition(ListNode* head, int x) {
        ListNode pre(0);
        ListNode post(0);
        ListNode* p1 = &pre;
        ListNode* p2 = &post;
        
        while (head)
        {
            if (head->val < x) p1 = p1->next = head;
            else p2 = p2->next = head;
            head = head->next;
        }
        p2->next = NULL;
        p1->next = post.next;
        return pre.next;
    }    
};