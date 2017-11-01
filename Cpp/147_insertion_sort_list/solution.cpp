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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode* _head = new ListNode(0);
        _head->next = head;
        ListNode* pre = _head;
        ListNode* cur = head;
        while (cur) 
        {
            // move forward to find the appropriate position to insert 
            if (cur->next && cur->next->val < cur->val) 
            {
                while (pre->next && pre->next->val < cur->next->val) pre = pre->next;
                ListNode* tmp = pre->next;
                pre->next = cur->next;
                cur->next = cur->next->next;
                pre->next->next = tmp;
                pre = _head;
            }
            else cur = cur->next;
        }
        ListNode* res = _head->next;
        delete _head;
        return res;
    }
};