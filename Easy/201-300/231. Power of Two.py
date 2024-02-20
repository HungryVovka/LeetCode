# 231. Power of Two
# 
# Given an integer n, return true if it is a power of two. Otherwise, return false.
# 
# An integer n is a power of two, if there exists an integer x such that n == 2x.
# 
# Example 1:
# Input: n = 1
# Output: true
# Explanation: 20 = 1
# 
# Example 2:
# Input: n = 16
# Output: true
# Explanation: 24 = 16
# 
# Example 3:
# Input: n = 3
# Output: false
# 
# Constraints:
# 
# -2^31 <= n <= 2^31 - 1

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False
        while n != 1:
            if n % 2 != 0:
                return False
            n //= 2
        return

# or

class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        return (n & (n - 1)) == 0 and n > 0

# Tasks are the property of LeetCode (https://leetcode.com/) 
# and users of this resource.
# 
# All solution code in this repository 
# is the personal property of Vladimir Rukavishnikov
# (vladimirrukavishnikovmail@gmail.com).