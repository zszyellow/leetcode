/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        /* Iteration, TC: O(N), SC: O(N) */
        // vector<ImmutableListNode*> nodes;
        // while (head != nullptr) {
        //     nodes.push_back(head);
        //     head = head->getNext();
        // }
        // for (int i = nodes.size()-1; i >= 0; --i) {
        //     nodes[i]->printValue();
        // }
        
        /* Recursive, TC: O(N), SC: O(N) */
        // if (head == nullptr) return;
        // printLinkedListInReverse(head->getNext());
        // head->printValue();
        
        /* Two nested iterations, TC: O(N^2) SC: O(1) */
        // for (ImmutableListNode* tail = nullptr, *cur = head; head != tail; tail = cur) {
        //     for (cur = head; cur->getNext() != tail; cur = cur->getNext());
        //     cur->printValue();
        // }
        
        /* Transfrom list to 2-D martix, then iterate every row
           TC: O(N), SC: O(sqrt(N)) 
        */
        // get linked-list count
        int count = 0;
        ImmutableListNode* cur = head;
        while (cur != nullptr) {
            ++ count;
            cur = cur->getNext();
        }
        
        // get row size of 2-D matrix and store starting positions of each row
        int n = ceil(sqrt(count));
        vector<ImmutableListNode*> start_poses;
        cur = head;
        count = -1;
        while (cur != nullptr) {
            ++ count;
            if (count % n == 0) start_poses.push_back(cur);
            cur = cur->getNext();
        }

        // print every row in reverse
        for (int i = start_poses.size()-1; i >= 0; -- i) {
            auto node = start_poses[i];
            vector<ImmutableListNode*> row;
            for (int i = 0; i < n; ++ i) {
                row.push_back(node);
                node = node->getNext();
                if (node == nullptr) break;
            }

            for (int j = row.size()-1; j >= 0; -- j) row[j]->printValue();
        }
    }
};