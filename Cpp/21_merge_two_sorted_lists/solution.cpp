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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* cur = NULL;
        if (l1 == NULL && l2 == NULL) return res;
        else if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        
        if (l1->val < l2->val)
        {
            res = l1;
            l1 = l1->next;
        }
        else 
        {
            res = l2;
            l2 = l2->next;
        }
        cur = res;
        
    
        while (l1 != NULL || l2 != NULL)
        {
            if (l1 == NULL)
            {
                cur->next = l2;   
                cur = cur->next;
                l2 = l2->next;
            }
            else if (l2 == NULL)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else if (l1->val < l2->val)
            {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else 
            {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next; 
            }
        }
        
        return res;
    }
};