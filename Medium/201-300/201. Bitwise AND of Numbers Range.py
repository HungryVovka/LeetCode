# 201. Bitwise AND of Numbers Range
# 
# Given two integers left and right that represent the range [left, right], return the 
# bitwise AND of all numbers in this range, inclusive.
# 
# Example 1:
# Input: left = 5, right = 7
# Output: 4
# 
# Example 2:
# Input: left = 0, right = 0
# Output: 0
# 
# Example 3:
# Input: left = 1, right = 2147483647
# Output: 0
# 
# Constraints:
# 
# 0 <= left <= right <= 2^31 - 1

class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        left_shift = 0
        while left != right:
            left_shift += 1
            left >>= 1
            right >>= 1
        return left << left_shift

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).