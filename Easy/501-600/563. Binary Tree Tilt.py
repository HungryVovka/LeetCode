# 563. Binary Tree Tilt
# 
# Given the root of a binary tree, return the sum of every tree node's tilt.
# 
# The tilt of a tree node is the absolute difference between the sum of all left subtree node 
# values and all right subtree node values. If a node does not have a left child, then the sum 
# of the left subtree node values is treated as 0. The rule is similar if the node does not have a 
# right child.
# 
# Example 1:
# Input: root = [1,2,3]
# Output: 1
# Explanation: 
# Tilt of node 2 : |0-0| = 0 (no children)
# Tilt of node 3 : |0-0| = 0 (no children)
# Tilt of node 1 : |2-3| = 1 (left subtree is just left child, so 
# sum is 2; right subtree is just right child, so sum is 3)
# Sum of every tilt : 0 + 0 + 1 = 1
# 
# Example 2:
# Input: root = [4,2,9,3,5,null,7]
# Output: 15
# Explanation: 
# Tilt of node 3 : |0-0| = 0 (no children)
# Tilt of node 5 : |0-0| = 0 (no children)
# Tilt of node 7 : |0-0| = 0 (no children)
# Tilt of node 2 : |3-5| = 2 (left subtree is just left child, so 
# sum is 3; right subtree is just right child, so sum is 5)
# Tilt of node 9 : |0-7| = 7 (no left child, so sum is 0; right 
# subtree is just right child, so sum is 7)
# Tilt of node 4 : |(3+5+2)-(9+7)| = |10-16| = 6 (left subtree 
# values are 3, 5, and 2, which sums to 10; right subtree values 
# are 9 and 7, which sums to 16)
# Sum of every tilt : 0 + 0 + 0 + 2 + 7 + 6 = 15
# 
# Example 3:
# Input: root = [21,7,14,1,1,2,2,3,3]
# Output: 9
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [0, 104].
# -1000 <= Node.val <= 1000

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        full_tilt = 0
        stack = []
        stack.append(root)
        while stack:
            node: TreeNode = stack.pop()
            if node:
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
                full_tilt += abs( \
                self.sum_tree(node.left) - self.sum_tree(node.right))
        return full_tilt

    def sum_tree(self, node: Optional[TreeNode]) -> int:
        if not node:
            return 0
        return node.val + self.sum_tree(node.left) + self.sum_tree(node.right)

# or

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        full_tilt = 0
        stack = []
        stack.append(root)
        cache = {}
        while stack:
            node: TreeNode = stack.pop()
            if node:
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)         
                left_sum = self.get_sum(node.left, cache)
                right_sum = self.get_sum(node.right, cache)
                full_tilt += abs(left_sum - right_sum)
        return full_tilt
    
    def get_sum(self, node: Optional[TreeNode], cache: dict) -> int:
        if not node:
            return 0
        if node in cache:
            return cache[node]
        sum_val = node.val + \
        self.get_sum(node.left, cache) + self.get_sum(node.right, cache)
        cache[node] = sum_val
        return sum_val

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).