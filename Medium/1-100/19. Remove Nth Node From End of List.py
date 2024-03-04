# 19. Remove Nth Node From End of List
# 
# Given the head of a linked list, remove the nth node from the end of the list and return its 
# head.
# 
# Example 1:
# Input: head = [1,2,3,4,5], n = 2
# Output: [1,2,3,5]
# 
# Example 2:
# Input: head = [1], n = 1
# Output: []
# 
# Example 3:
# Input: head = [1,2], n = 1
# Output: [1]
# 
# Constraints:
# 
# The number of nodes in the list is sz.
# 1 <= sz <= 30
# 0 <= Node.val <= 100
# 1 <= n <= sz

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy_node = ListNode(0)
        dummy_node.next = head
        fast, slow = dummy_node, dummy_node
        i = 0
        while i <= n:
            fast = fast.next
            i += 1
        while fast:
            fast, slow = fast.next, slow.next
        slow.next = slow.next.next
        return dummy_node.next

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).