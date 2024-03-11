# 94. Binary Tree Inorder Traversal
# 
# Given the root of a binary tree, return the inorder traversal of its nodes' values.
# 
# Example 1:
# Input: root = [1,null,2,3]
# Output: [1,3,2]
# 
# Example 2:
# Input: root = []
# Output: []
# 
# Example 3:
# Input: root = [1]
# Output: [1]
# 
# Constraints:
# 
# The number of nodes in the tree is in the range [0, 100].
# -100 <= Node.val <= 100

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        answer = []
        stack = []
        current_node = root
        while current_node or stack:
            while current_node:
                stack.append(current_node)
                current_node = current_node.left
            current_node = stack.pop()
            answer.append(current_node.val)
            current_node = current_node.right
        return answer

# or

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        def inorder(node, answer):
            if node:
                inorder(node.left, answer)
                answer.append(node.val)
                inorder(node.right, answer)
        answer = []
        inorder(root, answer)
        return answer

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).