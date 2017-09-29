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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        
        ListNode* start = head, *end = head;
        ListNode* res = new ListNode(0);  
        auto cur = res;
        while(true) 
        {
            int i;
            for (i = 0; i < k; ++ i) 
            {         
                if (end) end = end->next;
                else break;
            }
            if (i <= k - 1) break;
            // 头插法
            auto start_copy = start;         
            while (start != end) 
            {          
                auto tmp = start;
                start = start->next;
                tmp->next = cur->next;
                cur->next = tmp;
            }
            cur = start_copy;                       
            start = end;
        }
        cur->next = start;
        return res->next;
    }
};