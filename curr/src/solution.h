#ifndef PRACTICE_SOLUTION_H
#define PRACTICE_SOLUTION_H

/*
https://leetcode.com/problems/add-two-numbers/

2. Add Two Numbers
Medium
25.4K
4.9K
Companies
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



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
It is guaranteed that the list represents a number that does not have leading zeros.
Accepted
3.6M
Submissions
8.8M
Acceptance Rate
40.4%

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
        // we must visit every node eventually
        // carry is at most 1, as adding two digits
        // the lengths of the linked are unknown and not necessarily the same
        // No leading zeros
        // List cannot be empty, but can have up to 100 digits
        // Overflow? Irrelevant as the return value is also a linked list.

        // initialize and process the first node
        ListNode* result = new ListNode(l1->val + l2->val);

        // while l1 and l2 both have remaining nodes
            // add two digits and calculate carry
            // create a new node with the remainder
            // move to the next node
        // if l1 has remaining nodes
            // add carry to the first remaining node
            // while l1 has remainig nodes
                // copy the node
            // return the result
        // if l2 has remaining nodes
            // add carry to the second remaining node
            // while l2 has remaining nodes
                // copy the node
            // return the result
        // both of them have no remaining nodes
        // create the last node if there was carry
        // return the result
    }
};

#endif // PRACTICE_SOLUTION_H
