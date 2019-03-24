/*
 * @lc app=leetcode id=369 lang=cpp
 *
 * [369] Plus One Linked List
 *
 * https://leetcode.com/problems/plus-one-linked-list/description/
 *
 * algorithms
 * Medium (55.75%)
 * Total Accepted:    32.1K
 * Total Submissions: 57.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-negative integer represented as non-empty a singly linked list
 * of digits, plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the
 * number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list.
 * 
 * 
 * Example :
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * 
 * 
 * 
 */
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
    ListNode* plusOne(ListNode* head) {
        if (!head) return new ListNode(1);
        auto plused = plusOne(head->next);
        head->val += plused != head->next;
        if (head->val <= 9) return head;
        head->val = 0;
        // for the case that the whole number is 9 or 99, etc
        plused->next = head;
        return plused;
    }
};

