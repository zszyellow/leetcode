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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        // calculate length of the linkedlist
        int len = 0;
        for (ListNode* tmp = head; tmp != NULL; tmp = tmp->next) len ++;
        if (k % len == 0) return head;
        k %= len;
        
        ListNode* tmp = head;
        ListNode* res = NULL;
        for (int i = 0; i < len-k-1; i ++) tmp = tmp->next;
        res = tmp->next;
        tmp->next = NULL;
        tmp = res;
        while (tmp->next != NULL) tmp = tmp->next;
        tmp->next = head;
        
        return res;
    }
};