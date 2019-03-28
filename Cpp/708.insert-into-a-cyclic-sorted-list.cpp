/*
 * @lc app=leetcode id=708 lang=cpp
 *
 * [708] Insert into a Cyclic Sorted List
 *
 * https://leetcode.com/problems/insert-into-a-cyclic-sorted-list/description/
 *
 * algorithms
 * Medium (28.50%)
 * Total Accepted:    12.5K
 * Total Submissions: 43.9K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":{"$id":"3","next":{"$ref":"1"},"val":1},"val":4},"val":3}\n2'
 *
 * Given a node from a cyclic linked list which is sorted in ascending order,
 * write a function to insert a value into the list such that it remains a
 * cyclic sorted list. The given node can be a reference to any single node in
 * the list, and may not be necessarily the smallest value in the cyclic list.
 * 
 * If there are multiple suitable places for insertion, you may choose any
 * place to insert the new value. After the insertion, the cyclic list should
 * remain sorted.
 * 
 * If the list is empty (i.e., given node is null), you should create a new
 * single cyclic list and return the reference to that single node. Otherwise,
 * you should return the original given node.
 * 
 * The following example may help you understand the problem better:
 * 
 * 
 * 
 * 
 * 
 * In the figure above, there is a cyclic sorted list of three elements. You
 * are given a reference to the node with value 3, and we need to insert 2 into
 * the list.
 * 
 * 
 * 
 * 
 * 
 * The new node should insert between node 1 and node 3. After the insertion,
 * the list should look like this, and we should still return node 3.
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* res = new Node(insertVal, nullptr);
            res->next = res;
            return res;
        }
        else if (head->next == head) {
            Node* node = new Node(insertVal, head);
            head->next = node;
            return head;
        }
        else {
            Node* cur = head;
            bool flag = false;

            while (cur) {
                if (cur->val <= insertVal && cur->next->val >= insertVal) {
                    Node* next = cur->next;
                    Node* node = new Node(insertVal, next);
                    cur->next = node;
                    return head;
                }
                if (cur == head && flag) break;
                cur = cur->next;
                flag = true;
            }

            // the minimum or the maximum
            flag = false;
            while (cur) {
                if (cur->next->val < cur->val) {
                    Node* next = cur->next;
                    cur->next = new Node(insertVal, next);
                    return head;
                }
                if (cur == head && flag) break;
                cur = cur->next;
                flag = true;
            }

            // all the nodes with the same value
            Node* next = head->next;
            head->next = new Node(insertVal, next);
            return head;
        } 
    }
};

