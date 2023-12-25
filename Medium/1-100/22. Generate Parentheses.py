# 22. Generate Parentheses
# 
# Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
# 
# Example 1:
# 
# Input: n = 3
# Output: ["((()))","(()())","(())()","()(())","()()()"]
# 
# Example 2:
# 
# Input: n = 1
# Output: ["()"]
# 
# Constraints:
# 
# 1 <= n <= 8

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def combination(s, left, right):
            if len(s) == n * 2:
                yield s
                return
            if left < n:
                yield from combination(s + "(", left + 1, right)
            if right < left:
                yield from combination(s + ")", left, right + 1)
        return list(combination("", 0, 0))

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).