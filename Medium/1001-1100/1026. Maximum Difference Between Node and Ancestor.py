# 1026. Maximum Difference Between Node and Ancestor
# 
# Given the root of a binary tree, find the maximum value v for which there exist different nodes a and 
# b where v = |a.val - b.val| and a is an ancestor of b.
# 
# A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.
# 
# Example 1:
# Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
# Output: 7
# Explanation: We have various ancestor-node differences, some of which are given below :
# |8 - 3| = 5
# |3 - 7| = 4
# |8 - 1| = 7
# |10 - 13| = 3
# Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
# 
# Example 2:
# Input: root = [1,null,2,null,0,3]
# Output: 3
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [2, 5000].
# 0 <= Node.val <= 105

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.max_difference = 0
        self.dfs(root, root.val, root.val)
        return self.max_difference

    def dfs(self, root: TreeNode, min_val: int, max_val: int) -> None:
        if root is None:
            return
        self.max_difference = max(self.max_difference, \
        abs(max_val - root.val), \
        abs(min_val - root.val))
        min_val = min(min_val, root.val)
        max_val = max(max_val, root.val)
        self.dfs(root.left, min_val, max_val)
        self.dfs(root.right, min_val, max_val)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).