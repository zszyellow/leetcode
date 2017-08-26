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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(0);
        ListNode* tmp = start;
        
        bool isOverTen = false, isL1Finished = false, isL2Finished = false, isStart = true;
        while (!isL1Finished || !isL2Finished || isOverTen)
        {
            int x1 = 0, x2 = 0, sum = 0;
            if (!isL1Finished) x1 = l1->val;
            if (!isL2Finished) x2 = l2->val;
            if (isOverTen) sum = x1 + x2 + 1;
            else sum = x1 + x2;
            if (sum >= 10) isOverTen = true;
            else isOverTen = false;
            if (isStart) 
            {
                tmp->val = sum % 10;
                isStart = false;
            }
            else 
            {
                auto tmp2 = new ListNode(sum % 10);
                tmp->next = tmp2;
                tmp = tmp2;
            }
            if (l1->next == NULL) isL1Finished = true;
            else l1 = l1->next;
            if (l2->next == NULL) isL2Finished = true;
            else l2 = l2->next;
        }
        
        return start;
    }
};