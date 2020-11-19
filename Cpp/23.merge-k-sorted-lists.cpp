class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [](const ListNode *lhs, const ListNode *rhs) {
            return lhs->val > rhs->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> pq(comp);
        ListNode *dummy = new ListNode(0), *cur = dummy;
        
        for (auto list : lists) {
            if (list != nullptr) pq.push(list);   
        }
            
        while(!pq.empty()) {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
            if (cur->next != nullptr) pq.push(cur->next);
        }
        
        return dummy->next;
    }
};