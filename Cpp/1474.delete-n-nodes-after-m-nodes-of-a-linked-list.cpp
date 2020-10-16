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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode *cur = head;
        ListNode *chunk_end = head;
        
        while (cur != nullptr) {
            int m_count(m), n_count(n);
            
            while (cur != nullptr && m_count > 0) {
                chunk_end = cur;
                cur = cur->next;
                m_count --;
            }
            
            while (cur != nullptr && n_count > 0) {
                cur = cur->next;
                n_count --;
            }
            chunk_end->next = cur;
        }
        
        return head;
    }
};