class Solution {
public:
    struct cmpNode 
    {
        bool operator()(ListNode *p, ListNode *q) const
        {
            return p->val > q->val;
        }  
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmpNode> pq;
        ListNode* root = new ListNode(0), *cur = root;
        
        for(int i = 0; i < lists.size(); i ++) 
            if(lists[i] != NULL) pq.push(lists[i]);
            
        while(!pq.empty()) 
        {
            cur->next = pq.top();
            cur = cur->next;
            pq.pop();
            if(cur->next != NULL) pq.push(cur->next);
        }
        
        return root->next;
    }
};