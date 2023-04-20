#ifndef PRACTICE_SOLUTION_H
#define PRACTICE_SOLUTION_H

/*
https://leetcode.com/problems/add-two-numbers/

2. Add Two Numbers
Medium
25.4K
4.9K
Companies
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a
single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.



Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading
zeros. Accepted 3.6M Submissions 8.8M Acceptance Rate 40.4%

*/

#include "debug.h"
#include "list.h"

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = l1->val + l2->val;
        if (sum > 9) {
            carry = 1;
            sum -= 10;
        }
        ListNode* result = new ListNode(sum);
        ListNode* currNode = result;

        while (l1->next && l2->next) {
            l1 = l1->next;
            l2 = l2->next;
            sum = l1->val + l2->val + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            currNode->next = new ListNode(sum);
            currNode = currNode->next;
        }
        while (l1->next) {
            l1 = l1->next;
            sum = l1->val + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            currNode->next = new ListNode(sum);
            currNode = currNode->next;
        }
        while (l2->next) {
            l2 = l2->next;
            sum = l2->val + carry;
            carry = 0;
            if (sum > 9) {
                carry = 1;
                sum -= 10;
            }
            currNode->next = new ListNode(sum);
            currNode = currNode->next;
        }
        if (carry) {
            currNode->next = new ListNode(carry);
        }
        return result;
    }
};

#endif  // PRACTICE_SOLUTION_H
