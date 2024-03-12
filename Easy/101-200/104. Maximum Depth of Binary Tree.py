# 104. Maximum Depth of Binary Tree
# 
# Given the root of a binary tree, return its maximum depth.
# 
# A binary tree's maximum depth is the number of nodes along the longest path from the 
# root node down to the farthest leaf node.
# 
# Example 1:
# Input: root = [3,9,20,null,null,15,7]
# Output: 3
# 
# Example 2:
# Input: root = [1,null,2]
# Output: 2
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [0, 104].
# -100 <= Node.val <= 100

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        max_depth = 0
        queue = [root]
        while queue:
            max_depth += 1
            size = len(queue)
            for i in range(size):
                node = queue.pop(0)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        return max_depth

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).