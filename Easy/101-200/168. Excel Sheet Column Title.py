# 168. Excel Sheet Column Title
# 
# Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
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
# Example 1:
# 
# Input: columnNumber = 1
# Output: "A"
# 
# Example 2:
# 
# Input: columnNumber = 28
# Output: "AB"
# 
# Example 3:
# 
# Input: columnNumber = 701
# Output: "ZY"

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        if columnNumber == 0:
            return ""
        else:
            return self.convertToTitle(\
            (columnNumber - 1) // 26) + \
            chr((columnNumber - 1) % 26 + ord('A'))

# or

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        answer = ""
        while columnNumber > 0:
            index = (columnNumber - 1) % 26
            answer = chr(index + ord('A')) + answer
            columnNumber = (columnNumber - 1) // 26
        return answer

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).