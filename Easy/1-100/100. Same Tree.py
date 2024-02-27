# 100. Same Tree
# 
# Given the roots of two binary trees p and q, write a function to check if they are the same 
# or not.
# 
# Two binary trees are considered the same if they are structurally identical, and the nodes 
# have the same value.
# 
# Example 1:
# Input: p = [1,2,3], q = [1,2,3]
# Output: true
# 
# Example 2:
# Input: p = [1,2], q = [1,null,2]
# Output: false
# 
# Example 3:
# Input: p = [1,2,1], q = [1,1,2]
# Output: false
# 
# Constraints:
# 
# The number of nodes in both trees is in the range [0, 100].
# -10^4 <= Node.val <= 10^4

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        stack = [(p, q)]
        while stack:
            node1, node2 = stack.pop()
            if not node1 and not node2:
                continue
            if not node1 or not node2 or node1.val != node2.val:
                return False
            stack.append((node1.left, node2.left))
            stack.append((node1.right, node2.right))
        return True

# or

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        return str(p) == str(q)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).