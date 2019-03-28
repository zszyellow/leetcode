/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 *
 * https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
 *
 * algorithms
 * Medium (41.04%)
 * Total Accepted:    17.9K
 * Total Submissions: 43.6K
 * Testcase Example:  '{"$id":"1","child":null,"next":{"$id":"2","child":null,"next":{"$id":"3","child":{"$id":"7","child":null,"next":{"$id":"8","child":{"$id":"11","child":null,"next":{"$id":"12","child":null,"next":null,"prev":{"$ref":"11"},"val":12},"prev":null,"val":11},"next":{"$id":"9","child":null,"next":{"$id":"10","child":null,"next":null,"prev":{"$ref":"9"},"val":10},"prev":{"$ref":"8"},"val":9},"prev":{"$ref":"7"},"val":8},"prev":null,"val":7},"next":{"$id":"4","child":null,"next":{"$id":"5","child":null,"next":{"$id":"6","child":null,"next":null,"prev":{"$ref":"5"},"val":6},"prev":{"$ref":"4"},"val":5},"prev":{"$ref":"3"},"val":4},"prev":{"$ref":"2"},"val":3},"prev":{"$ref":"1"},"val":2},"prev":null,"val":1}'
 *
 * You are given a doubly linked list which in addition to the next and
 * previous pointers, it could have a child pointer, which may or may not point
 * to a separate doubly linked list. These child lists may have one or more
 * children of their own, and so on, to produce a multilevel data structure, as
 * shown in the example below.
 * 
 * Flatten the list so that all the nodes appear in a single-level, doubly
 * linked list. You are given the head of the first level of the list.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * ⁠1---2---3---4---5---6--NULL
 * ⁠        |
 * ⁠        7---8---9---10--NULL
 * ⁠            |
 * ⁠            11--12--NULL
 * 
 * Output:
 * 1-2-3-7-8-11-12-9-10-4-5-6-NULL
 * 
 * 
 * 
 * 
 * Explanation for the above example:
 * 
 * Given the following multilevel doubly linked list:
 * 
 * 
 * 
 * 
 * 
 * 
 * We should return the following flattened doubly linked list:
 * 
 * 
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        flattenTail(head);
        return head;
    }

    Node* flattenTail(Node* head) {
        if (!head) return nullptr;
        if (!head->child) {
            if (!head->next) return head;
            return flattenTail(head->next);
        }
        else {
            Node* child = head->child;
            head->child = nullptr;
            Node* next = head->next;
            Node* child_tail = flattenTail(child);
            head->next = child;
            child->prev = head;
            if (next) {
                child_tail->next = next;
                next->prev = child_tail;
                return flattenTail(next);
            }
            return child_tail;
        }
    }
};

