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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur = head;
        ListNode* res = head;
        int numOfNode = 0;
        vector<ListNode*> list;
        while (cur != NULL)
        {
            numOfNode ++;
            list.push_back(cur);
            cur = cur->next;
        }
        cout << numOfNode << endl;
        if (numOfNode == n) res = head->next;
        else list[numOfNode-n-1]->next = list[numOfNode-n]->next;
        return res;
    }
};