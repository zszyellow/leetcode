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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode* oneStep(head);
        ListNode* twoStep(head);
        bool isThereCycle = false;
        
        while (twoStep && twoStep->next)
        {
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
            if (oneStep==twoStep) 
            {
                isThereCycle = true;
                break;
            }
        }
        
        if (!isThereCycle) return NULL;
        oneStep = head;
        while (oneStep != twoStep)
        {
            oneStep = oneStep->next;
            twoStep = twoStep->next;
        }
        return oneStep;
    }
};