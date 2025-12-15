# 2. Add Two Numbers
# 
# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse 
# order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the number 0 itself.
# 
# Example 1:
# 
# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.
# 
# Example 2:
# 
# Input: l1 = [0], l2 = [0]
# Output: [0]
# 
# Example 3:
# 
# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]
# 
# Constraints:
# 
# The number of nodes in each linked list is in the range [1, 100].
# 0 <= Node.val <= 9
# It is guaranteed that the list represents a number that does not have leading zeros.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        answer = ListNode(0)
        current_node = answer
        portable = 0
        while l1 or l2 or portable:
            num_1 = l1.val if l1 else 0
            num_2 = l2.val if l2 else 0
            curr_node_sum = num_1 + num_2 + portable
            portable = curr_node_sum // 10
            number = curr_node_sum % 10
            current_node.next = ListNode(number)
            current_node = current_node.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return answer.next

# or

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        tail = dummy
        carry = 0
        while l1 is not None or l2 is not None:
            temp_sum = carry
            if l1 is not None:
                temp_sum += l1.val
                l1 = l1.next
            if l2 is not None:
                temp_sum += l2.val
                l2 = l2.next
            carry = 1 if temp_sum >= 10 else 0
            tail.next = ListNode(temp_sum - 10 if carry else temp_sum)
            tail = tail.next
        if carry:
            tail.next = ListNode(1)
        return dummy.next

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).