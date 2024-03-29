# 1422. Maximum Score After Splitting a String
# 
# Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. 
# left substring and right substring).
# 
# The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right 
# substring.
# 
# Example 1:
# 
# Input: s = "011101"
# Output: 5 
# Explanation: 
# All possible ways of splitting s into two non-empty substrings are:
# left = "0" and right = "11101", score = 1 + 4 = 5 
# left = "01" and right = "1101", score = 1 + 3 = 4 
# left = "011" and right = "101", score = 1 + 2 = 3 
# left = "0111" and right = "01", score = 1 + 1 = 2 
# left = "01110" and right = "1", score = 2 + 1 = 3
# 
# Example 2:
# 
# Input: s = "00111"
# Output: 5
# Explanation: When left = "00" and right = "111", we get the maximum score = 2 + 3 = 5
# 
# Example 3:
# 
# Input: s = "1111"
# Output: 3
# 
# Constraints:
# 
# 2 <= s.length <= 500
# The string s consists of characters '0' and '1' only.

class Solution:
    def maxScore(self, s: str) -> int:
        ways = [(s[:i], s[i:]) for i in range(1, len(s))]
        scores = list(map(lambda x: x[0].count("0") + x[1].count("1"), ways))
        return max(scores)

# or

class Solution:
    def maxScore(self, s: str) -> int:
        max_score, zero = 0, 0
        one = s.count("1")
        i = 0
        while i < len(s) - 1:
            if s[i] == "0":
                zero += 1
            elif s[i] == "1":
                one -= 1
            max_score = max(max_score, zero + one)
            i += 1
        return max_score

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).