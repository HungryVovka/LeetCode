# 1609. Even Odd Tree
# 
# A binary tree is named Even-Odd if it meets the following conditions:
# 
# The root of the binary tree is at level index 0, its children are at level index 1, their 
# children are at level index 2, etc.
# For every even-indexed level, all nodes at the level have odd integer values in strictly 
# increasing order (from left to right).
# For every odd-indexed level, all nodes at the level have even integer values in strictly 
# decreasing order (from left to right).
# 
# Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return 
# false.
# 
# Example 1:
# Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
# Output: true
# Explanation: The node values on each level are:
# Level 0: [1]
# Level 1: [10,4]
# Level 2: [3,7,9]
# Level 3: [12,8,6,2]
# Since levels 0 and 2 are all odd and increasing and levels 1 and 
# 3 are all even and decreasing, the tree is Even-Odd.
# 
# Example 2:
# Input: root = [5,4,2,3,3,7]
# Output: false
# Explanation: The node values on each level are:
# Level 0: [5]
# Level 1: [4,2]
# Level 2: [3,3,7]
# Node values in level 2 must be in strictly increasing order, so 
# the tree is not Even-Odd.
# 
# Example 3:
# Input: root = [5,9,1,3,5,7]
# Output: false
# Explanation: Node values in the level 1 should be even integers.
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [1, 10^5].
# 1 <= Node.val <= 10^6

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: Optional[TreeNode]) -> bool:
        queue = deque([root])
        level = 0
        while queue:
            size = len(queue)
            prev = None
            i = 0
            while i < size:
                node = queue.popleft()
                if level % 2 == 0:
                    if node.val % 2 == 0 \
                    or (prev != None and prev >= node.val):
                        return False
                if level % 2 == 1:
                    if node.val % 2 == 1 \
                    or (prev != None and prev <= node.val):
                        return False
                prev = node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                i += 1
            level += 1
        return True

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).