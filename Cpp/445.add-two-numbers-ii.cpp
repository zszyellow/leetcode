/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 *
 * https://leetcode.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (49.49%)
 * Total Accepted:    83.5K
 * Total Submissions: 168.6K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The most significant digit comes first and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the
 * lists is not allowed.
 * 
 * 
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1, num2;
        while (l1) {
            num1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            num2.push_back(l2->val);
            l2 = l2->next;
        }

        int m = num1.size();
        int n = num2.size();
        int sum = 0;
        int carry = 0;
        ListNode* head(nullptr);
        ListNode* cur(nullptr);

        for (int i = m-1, j = n-1; i >=0 || j >=0 || carry > 0; i --, j --) {
            sum = carry;
            if (i >= 0) sum += num1[i];
            if (j >= 0) sum += num2[j];
            carry = sum >= 10;
            cur = new ListNode(sum%10);
            cur->next = head;
            head = cur;
        }

        return head;
    }
};

