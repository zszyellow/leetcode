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
    vector<int> nextLargerNodes(ListNode* head) {
        if (head == nullptr) return vector<int>();
        ListNode* cur = head;
        int size = 0;
        while (cur) {
            cur = cur->next;
            size ++;
        }
        
        cur = head;
        vector<int> res(size, 0);
        stack<pair<int, int>> st;
        int i = 0;
        while (cur) {
            while (!st.empty() && st.top().second < cur->val) {
                res[st.top().first] = cur->val;
                st.pop();
            }
            st.push({i, cur->val});
            i ++;
            cur = cur->next;
        }
        return res;
    }
};