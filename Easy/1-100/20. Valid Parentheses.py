# 20. Valid Parentheses
# 
# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
# 
# An input string is valid if:
# 
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
# 
# Example 1:
# 
# Input: s = "()"
# Output: true
# 
# Example 2:
# 
# Input: s = "()[]{}"
# Output: true
# 
# Example 3:
# 
# Input: s = "(]"
# Output: false
#  
# Constraints:
# 
# 1 <= s.length <= 10^4
# s consists of parentheses only '()[]{}'.

class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        brackets = {
            ")" : "(",
            "]" : "[",
            "}" : "{"
        }
        for i in s:
            if i in brackets.values():
                stack.append(i)
            elif i in brackets.keys():
                if len(stack) == 0 or brackets[i] != stack.pop():
                    return False
        return len(stack) == 0

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).