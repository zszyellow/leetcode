/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        unordered_map<int, ListNode*> hm;
        int sum = 0;
        while (head) {
            sum += head->val;
            hm[sum] = head;
            head = head->next;
        }
        
        head = dummy;
        sum = 0;
        while (head) {
            sum += head->val;
            if (hm.find(sum) != hm.end() && hm[sum] != head) {
                head->next = hm[sum]->next;
            }
            head = head->next;
        }
        return dummy->next;
    }
};