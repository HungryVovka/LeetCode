# 171. Excel Sheet Column Number
# 
# Given a string columnTitle that represents the column title as appears in an Excel sheet, 
# return its corresponding column number.
# 
# For example:
# 
# A -> 1
# B -> 2
# C -> 3
# ...
# Z -> 26
# AA -> 27
# AB -> 28 
# ...
#  
# 
# Example 1:
# Input: columnTitle = "A"
# Output: 1
# 
# Example 2:
# Input: columnTitle = "AB"
# Output: 28
# 
# Example 3:
# Input: columnTitle = "ZY"
# Output: 701
# 
# Constraints:
# 
# 1 <= columnTitle.length <= 7
# columnTitle consists only of uppercase English letters.
# columnTitle is in the range ["A", "FXSHRXW"].

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        answer = 0
        i = len(columnTitle) - 1
        position_value = 0
        while i >= 0:
            char_value = ord(columnTitle[i]) - ord('A') + 1
            answer += char_value * (26 ** position_value)
            position_value += 1
            i -= 1
        return answer

# or

class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        answer = 0
        for i in range(len(columnTitle) - 1, -1, -1):
            char_value = ord(columnTitle[i]) - ord('A') + 1
            position_value = len(columnTitle) - 1 - i
            answer += char_value * (26 ** position_value)
        return answer

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).