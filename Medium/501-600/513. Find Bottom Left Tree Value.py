# 513. Find Bottom Left Tree Value
# 
# Given the root of a binary tree, return the leftmost value in the last row of the tree.
# 
# Example 1:
# Input: root = [2,1,3]
# Output: 1
# 
# Example 2:
# Input: root = [1,2,3,4,null,5,6,null,null,7]
# Output: 7
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [1, 104].
# -2^31 <= Node.val <= 2^31 - 1

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def dfs(self, node: Optional[TreeNode], depth: int, \
    most_left: Optional[int], max_depth: int) -> Tuple[Optional[int], int]:
        if not node:
            return most_left, max_depth
        if depth > max_depth:
            most_left = node.val
            max_depth = depth
        most_left, max_depth = \
        self.dfs(node.left, depth + 1, most_left, max_depth)
        most_left, max_depth = \
        self.dfs(node.right, depth + 1, most_left, max_depth)
        return most_left, max_depth

    def findBottomLeftValue(self, root: Optional[TreeNode]) -> Optional[int]:
        most_left = None
        max_depth = -1
        most_left, max_depth = self.dfs(root, 0, most_left, max_depth)
        return most_left

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).