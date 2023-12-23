# 101. Symmetric Tree
# 
# Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
# 
# Example 1:
# 
# Input: root = [1,2,2,3,4,4,3]
# Output: true
# 
# Example 2:
# 
# Input: root = [1,2,2,null,3,null,3]
# Output: false
#  
# Constraints:
# 
# The number of nodes in the tree is in the range [1, 1000].
# -100 <= Node.val <= 100
#  
# Follow up: Could you solve it both recursively and iteratively?

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def isMirror(left, right):
            if left is None and right is None:
                return True
            if left is None or right is None:
                return False
            # check:
            current_nodes = (left.val == right.val)
            left_subtree = isMirror(left.left, right.right)
            right_subtree = isMirror(left.right, right.left)
            return current_nodes and left_subtree and right_subtree
        return True if root is None else isMirror(root.left, root.right)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).