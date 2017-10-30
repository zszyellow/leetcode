/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        if (m.find(head) == m.end())
        {
            m[head] = new RandomListNode(head->label);
            m[head]->next = copyRandomList(head->next);
            m[head]->random = copyRandomList(head->random);
        }
        return m[head];
    }
    
private:
    unordered_map<RandomListNode*, RandomListNode*> m;
};