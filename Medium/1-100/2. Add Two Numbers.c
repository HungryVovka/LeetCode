// 2. Add Two Numbers
// 
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse 
// order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// 
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
// 
// Example 1:
// 
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// 
// Example 2:
// 
// Input: l1 = [0], l2 = [0]
// Output: [0]
// 
// Example 3:
// 
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
// 
// Constraints:
// 
// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

#include <stdio.h>      // printf
#include <stdlib.h>     // malloc, fre

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* dummy_head;
    struct ListNode* current_node;
    struct ListNode* new_node;
    int carry;
    int current_sum;
    int num1, num2, digit;

    dummy_head = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy_head->val = 0;
    dummy_head->next = NULL;
    current_node = dummy_head;
    carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0){
        num1 = (l1 != NULL) ? l1->val : 0;
        num2 = (l2 != NULL) ? l2->val : 0;
        current_sum = num1 + num2 + carry;

        carry = current_sum / 10;
        digit = current_sum % 10;

        new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
        new_node->val = digit;
        new_node->next = NULL;

        current_node->next = new_node;
        current_node = new_node;

        l1 = (l1 != NULL) ? l1->next : NULL;
        l2 = (l2 != NULL) ? l2->next : NULL;
    }
    return dummy_head->next;
}

// Tasks are the property of LeetCode (https://leetcode.com/) 
// and users of this resource.
// 
// All solution code in this repository 
// is the personal property of Vladimir Rukavishnikov
// (vladimirrukavishnikovmail@gmail.com).