# 1457. Pseudo-Palindromic Paths in a Binary Tree
# 
# Given a binary tree where node values are digits from 1 to 9. A path in the binary tree is said to be 
# pseudo-palindromic if at least one permutation of the node values in the path is a palindrome.
# 
# Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
# 
# Example 1:
# Input: root = [2,3,1,3,1,null,1]
# Output: 2 
# Explanation: The figure above represents the given binary tree. There are 
# three paths going from the root node to leaf nodes: the red path [2,3,3], 
# the green path [2,1,1], and the path [2,3,1]. Among these paths only red path and green 
# path are pseudo-palindromic paths since the red path [2,3,3] 
# can be rearranged in [3,2,3] (palindrome) and the green path [2,1,1] can be 
# rearranged in [1,2,1] (palindrome).
# 
# Example 2:
# Input: root = [2,1,1,1,3,null,null,null,null,null,1]
# Output: 1 
# Explanation: The figure above represents the given binary tree. There are 
# three paths going from the root node to leaf nodes: the green path [2,1,1], 
# the path [2,1,3,1], and the path [2,1]. Among these paths only the green 
# path is pseudo-palindromic since [2,1,1] can be rearranged in [1,2,1] 
# (palindrome).
# 
# Example 3:
# Input: root = [9]
# Output: 1
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [1, 105].
# 1 <= Node.val <= 9

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        pseudo_palindromic = 0
        queue = [(root, [0] * 10)]
        while queue:
            node, digit_frequency = queue.pop(0)
            digit_frequency[node.val] += 1
            if not node.left and not node.right:
                odd_amount = sum(i % 2 != 0 for i in digit_frequency)
                if odd_amount <= 1:
                    pseudo_palindromic += 1
            if node.left:
                queue.append((node.left, digit_frequency[:]))
            if node.right:
                queue.append((node.right, digit_frequency[:]))
        return pseudo_palindromic

# or

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: Optional[TreeNode]) -> int:
        def is_pseudo_palindrome(digit_frequency: List[int]) -> bool:
            return sum(i % 2 != 0 for i in digit_frequency) <= 1
        
        def dfs(node: TreeNode, digit_frequency: List[int]) -> int:
            if not node:
                return 0
            digit_frequency[node.val] += 1
            if not node.left and not node.right:
                return 1 if is_pseudo_palindrome(digit_frequency) else 0
            pseudo_palindromic = dfs(node.left, digit_frequency[:]) \
            + dfs(node.right, digit_frequency[:])
            digit_frequency[node.val] -= 1
            return pseudo_palindromic
        
        return dfs(root, [0] * 10)

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).